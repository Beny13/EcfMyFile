#ifndef WRITER_H
#define WRITER_H

#include <QString>
#include <QThread>

#include "zippedbufferpool.h"

class Writer : public QThread
{
public:
    Writer(ZippedBufferPool& pool, QString destination);
    void createFile();

private:
    ZippedBufferPool& _pool;
    QString _destination;
};

#endif // WRITER_H
