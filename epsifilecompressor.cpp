#include "epsifilecompressor.h"

#include "filepool.h"
#include "writer.h"
#include "zipper.h"
#include "zippedbufferpool.h"
#include "zippedbuffer.h"
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QDebug>
#include <QFileInfo>
#include <QDir>

using namespace std;

EpsiFileCompressor::EpsiFileCompressor() :
    _threadCount(1)
{
}

EpsiFileCompressor::EpsiFileCompressor(int threadCount) :
    _threadCount(threadCount)
{
}

void EpsiFileCompressor::compress(const QString &folder, const QString &ecfFileName)
{
    qDebug() << "EpsiFileCompressor::compress(" << folder << "," << ecfFileName << ")";
    // Only works on folders
    FilePool filePool(folder);
    ZippedBufferPool zippedBufferPool;
    Writer* writer = new Writer(zippedBufferPool, ecfFileName);
    writer->start();

    QList<Zipper*> zippers;
    for (int i = 0; i < _threadCount; ++i) {
        zippers.append(new Zipper(filePool, zippedBufferPool, filePool._canonicalRootPath));
    }

    for (Zipper* zipper : zippers) {
        zipper->wait();
        delete zipper;
    }

    writer->wait();
    delete writer;
}

void EpsiFileCompressor::uncompress(const QString &ecfFileName, const QString &folder)
{
    qDebug() << "EpsiFileCompressor::uncompress(" << ecfFileName << "," << folder << ")";

    // Checking if the folder already exists
    QFileInfo fileInfo("./" + folder);
    if (fileInfo.exists() && fileInfo.isFile()) {
        qDebug() << folder << " already exists";
        return;
    }

    // Reading zippedFile
    QFile zippedFile(ecfFileName);
    if (zippedFile.open(QIODevice::ReadOnly)) {
        QDataStream readStream(&zippedFile);
        QString filePath;
        ZippedBuffer buffer;
        while (!readStream.atEnd()) {
            // Filling the ZippedBuffer
            buffer.read(readStream);
            filePath = fileInfo.absolutePath() + "/" + folder + "/" + buffer.getRelativePath();

            // Creating parent directories if needed
            createFileParentDirectories(filePath);

            // Write to new file
            QFile unzippedFile(filePath);
            if (unzippedFile.open(QIODevice::WriteOnly)) {
                QDataStream newFileStream(&unzippedFile);
                QByteArray uncompressed = qUncompress(buffer.getZippedData());
                newFileStream.writeRawData(uncompressed.constData(), uncompressed.size());
            }
            unzippedFile.close();
        }
    }
}

void EpsiFileCompressor::createFileParentDirectories(QString filePath)
{
    QDir fakeDir(filePath);
    if (!fakeDir.exists()) {
        fakeDir.mkpath("..");
    }
}
