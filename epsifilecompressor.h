#ifndef EPSIFILECOMPRESSOR_H
#define EPSIFILECOMPRESSOR_H

#include "filepool.h"
#include "writer.h"

class EpsiFileCompressor
{
public:
    EpsiFileCompressor();
    EpsiFileCompressor(int threadCount);
    void compress(const QString &folder, const QString &ecfFileName);
    void uncompress(const QString &ecfFileName, const QString &folder);
private:
    int _threadCount;
};

#endif // EPSIFILECOMPRESSOR_H
