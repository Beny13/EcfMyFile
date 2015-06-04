#include "writer.h"

#include <QMutexLocker>
#include <QFile>
#include <QDataStream>

Writer::Writer(QString destination)
{
    this->_filename = destination;
}

void Writer::createFile(){
    QFile outfile(this->_filename+".ecf");
    outfile.open(QIODevice::WriteOnly);
    QDataStream out(&outfile);

    while(!this->_compressedDatas.isEmpty()) {
        out << qCompress(this->_compressedDatas.front());
        this->_compressedDatas.pop_front();
    }

    outfile.close();
}


void Writer::tryStoreByteArray(QByteArray compressedDatas, QString filename)
{
    QMutexLocker locker(&this->_mutex);
    this->_compressedDatas.push_back(compressedDatas);
    this->_filesnames.push_back(filename);
}
