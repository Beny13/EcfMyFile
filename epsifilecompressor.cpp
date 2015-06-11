#include "epsifilecompressor.h"

#include "filepool.h"
#include "writer.h"

EpsiFileCompressor::EpsiFileCompressor(int threadCount) :
    _threadCount(threadCount)
{
}

void EpsiFileCompressor::compress(const QString &folder, const QString &ecfFileName)
{
    // Only works on folders
    FilePool pool(QString(source));
    Writer writer(QString(destination));
}

void EpsiFileCompressor::uncompress(const QString &ecfFileName, const QString &folder)
{

}
