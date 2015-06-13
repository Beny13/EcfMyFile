#include "writer.h"

#include <QList>
#include <QMutexLocker>
#include <QFile>
#include <QDebug>

Writer::Writer(ZippedBufferPool &pool, const QString &destination) :
    QThread(nullptr), _pool(pool), _destination(destination)
{

}

void Writer::run()
{
    QFile outfile(this->_destination + ".ecf");
    outfile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QDataStream out(&outfile);

    QPair<bool, ZippedBuffer> pair = _pool.tryGet();
    while (pair.first) {
        pair.second.write(out);
        pair = _pool.tryGet();
    }

    outfile.close();
}
