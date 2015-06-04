#include "writer.h"

#include <QMutexLocker>
#include <QFile>
#include <QDataStream>

Writer::Writer(ZippedBufferPool pool, QString destination):_pool(pool),_destination(destination)
{

}

void Writer::createFile(){
    QFile outfile(this->_destination);
    outfile.open(QIODevice::WriteOnly);
    QDataStream out(&outfile);
    QPair<int,string> plop;
    plop.second;
    while(!this->_pool.isEmpty()) {
        out << this->_pool.front().second.getArray();
        this->_pool.pop_front();
    }

    outfile.close();
}
