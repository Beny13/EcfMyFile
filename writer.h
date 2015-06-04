#ifndef WRITER_H
#define WRITER_H

#include <QList>
#include <QString>
#include <QMutex>
#include <QByteArray>
#include <QThread>

class Writer : public QThread
{
public:
    Writer(ZippedBufferPool pool);
    void createFile();

private:
    ZippedBufferPool _pool;
    QString _destination;
};

#endif // WRITER_H
