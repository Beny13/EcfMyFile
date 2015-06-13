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
    _threadCount(0)
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
    QString baseFilePath = "./" + folder;

    QFileInfo fileInfo(baseFilePath);
    if (fileInfo.exists() && fileInfo.isFile()) {
        qDebug() << folder << " already exists";
        return;
    }

    qDebug() << fileInfo.absolutePath();


    // TEST
    /*
    QFileInfo yolo("./" + folder);
    qDebug() << yolo.absolutePath();
    QFile baseFolder("./" + folder + "/yololololol.txt");
    if (baseFolder.open(QIODevice::WriteOnly)) {
        QTextStream stream( &baseFolder );
        stream << "something" << endl;
    }
    baseFolder.close();
    return;*/

    qDebug() << "EpsiFileCompressor::uncompress(" << ecfFileName << "," << folder << ")";
    // BEN
    QFile zippedFile(ecfFileName);
    if (zippedFile.open(QIODevice::ReadOnly)) {
        QDataStream readStream(&zippedFile);
        QString filePath;
        ZippedBuffer buffer;
        while (!readStream.atEnd()) {
            buffer.read(readStream);
            filePath = fileInfo.absolutePath() + "/" + folder + "/" + buffer.getRelativePath();

            // TODO : Function
            {
                QDir tmp(filePath);
                if (!tmp.exists()) {
                    tmp.mkpath("..");
                }
            }

            QFile unzippedFile(filePath);
            if (unzippedFile.open(QIODevice::WriteOnly)) {
                QDataStream newFileStream(&unzippedFile);
                QByteArray uncompressed = qUncompress(buffer.getZippedData());
                qDebug() << uncompressed.size();
                newFileStream.writeRawData(uncompressed.constData(), uncompressed.size());
            }
            unzippedFile.close();
        }
        // QByteArray uncompressedArray(qUncompress(zippedFile.readAll()));
    }
    // JO
    /*
    QFile compressedFile(ecfFileName);
    if (compressedFile.open(QFile::ReadOnly) == true) {
        QByteArray uncompressedDatas = qUncompress(compressedFile.readAll());
        QFile uncompressedFile(folder + "uncompressed_" + ecfFileName);
        uncompressedFile.open(QFile::WriteOnly);
        QDataStream uncompressedStream(&uncompressedFile);
        //uncompressedStream.writeRawData(uncompressedArray.constData(),uncompressedArray.size());
    }*/

}
