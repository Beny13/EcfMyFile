#ifndef WRITER_H
#define WRITER_H

#include <QString>
#include <QThread>

#include "zippedbufferpool.h"

class Writer : public QThread
{
Q_OBJECT
public:
    Writer(ZippedBufferPool& pool, const QString &destination);
    virtual void run();
private:
    ZippedBufferPool& _pool;
    const QString& _destination;
};

#endif // WRITER_H
