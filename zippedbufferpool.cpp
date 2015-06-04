#include "zippedbufferpool.h"

#include <QMutexLocker>

ZippedBufferPool::ZippedBufferPool()
{
}

void ZippedBufferPool::put(ZippedBuffer &zb)
{
    QMutexLocker locker(&this->_mutex);
    _pool.append(zb);
}

void ZippedBufferPool::done()
{

}

QPair<bool, ZippedBuffer> ZippedBufferPool::tryGet()
{

}
