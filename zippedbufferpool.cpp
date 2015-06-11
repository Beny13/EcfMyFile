#include "zippedbufferpool.h"

#include <QMutexLocker>
#include <QDebug>

ZippedBufferPool::ZippedBufferPool()
{
    this->_done = false;
}

void ZippedBufferPool::put(ZippedBuffer &zb)
{
    QMutexLocker locker(&this->_mutex);
    _pool.append(zb);
    this->_cond.wakeAll();
}

void ZippedBufferPool::done()
{
    this->_done = true;
    this->_cond.wakeAll();
}

QPair<bool, ZippedBuffer> ZippedBufferPool::tryGet()
{
    QMutexLocker locker(&this->_mutex);

    if (_pool.isEmpty() && !_done)
        _cond.wait(&_mutex);

    if (_pool.isEmpty())
        return QPair<bool, ZippedBuffer>(false, ZippedBuffer());

    QPair<bool, ZippedBuffer> res = QPair<bool, ZippedBuffer>(true, _pool.front());
    _pool.pop_front();
    return res;
}
