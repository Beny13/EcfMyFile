#include "zipper.h"

#include <QDebug>

Zipper::Zipper(FilePool &pool, ZippedBufferPool &buffpool, const QString &rootpath)
    :_filepool(pool), _bufferpool(buffpool), _rootpath(rootpath)
{
    run();
}

void Zipper::run() {
    QString filename;
    filename = this->_filepool.tryGetFile();
    while(filename != "") {
        processFile(filename);
        filename = this->_filepool.tryGetFile();
    }

    _bufferpool.done();
}


void Zipper::processFile(const QString &filename) {
    QString relativePath = filename;
    relativePath = relativePath.replace(_rootpath, "");
    QFile file(filename);
    // Ouvertue du fichier en mode lecture seule
    if( file.open(QFile::ReadOnly) == true) {
        QByteArray datasFile = file.readAll(); //creation du QByteArray
        ZippedBuffer buff;
        QDataStream stream;
        stream << relativePath << qCompress(datasFile);
        buff.read(stream);
        this->_bufferpool.put(buff);
    }
}
