#include "zipper.h"

Zipper::Zipper(FilePool &pool, ZippedBufferPool &buffpool):_filepool(pool), _bufferpool(buffpool)
{
}

void Zipper::run(){
    QString filename;
    filename = this->_filepool.tryGetFile();
    while(filename != ""){
        processFile(filename);
        filename = this->_filepool.tryGetFile();
    }
}


void Zipper::processFile(const QString &filename) {
    QFile file(filename);
    // Ouvertue du fichier en mode lecture seule
    if( file.open(QFile::ReadOnly) == true) {
        QDataStream in(&file); //creation du QDataStream
        QByteArray tab = file.readAll(); //creation du QByteArray
        ZippedBuffer *buff;
        QDataStream qds;
        qds << filename << tab;
        buff->read(qds);
        this->_bufferpool.put(*buff);

    }
}
