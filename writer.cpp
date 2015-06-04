#include "writer.h"

#include <QList>
#include <QMutexLocker>
#include <QFile>

Writer::Writer(ZippedBufferPool &pool, QString destination) :
    _pool(pool), _destination(destination)
{
}

void Writer::createFile() {
    QFile outfile(this->_destination);
    outfile.open(QIODevice::WriteOnly & QIODevice::Truncate);
    QDataStream out(&outfile);

    QPair<bool, ZippedBuffer> pair = _pool.tryGet();
    while(pair.first)
        pair.second.write(out);

    outfile.close();
}
