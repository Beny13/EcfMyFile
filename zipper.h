#ifndef ZIPPER_H
#define ZIPPER_H
#include <QThread>
#include "filepool.h"
#include "zippedbufferpool.h"
#include "zippedbuffer.h"
#include <QFile>
class Zipper : public QThread
{
public:
    Zipper(FilePool &pool, ZippedBufferPool &buffpool);
    virtual void run();
private:
    void processFile(const QString &filename);
    FilePool &_filepool;
    ZippedBufferPool &_bufferpool;

};

#endif // ZIPPER_H
