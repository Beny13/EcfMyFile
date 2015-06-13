#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H

#include <QMutex>
#include <QWaitCondition>
#include "zippedbuffer.h"

class ZippedBufferPool
{
public:
    ZippedBufferPool();
    QPair<bool,ZippedBuffer> tryGet();
    void put(ZippedBuffer zb);
    void done();
private:
    QList<ZippedBuffer> _pool;
    QWaitCondition _cond;
    QMutex _mutex;
    bool _done;
};

#endif // ZIPPEDBUFFERPOOL_H
