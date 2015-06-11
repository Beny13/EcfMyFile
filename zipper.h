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
    Zipper(FilePool &pool, ZippedBufferPool &buffpool, const QString& rootpath);
    virtual void run();
private:
    void processFile(const QString &filename);
    FilePool &_filepool;
    ZippedBufferPool &_bufferpool;
    const QString& _rootpath;

};

#endif // ZIPPER_H
