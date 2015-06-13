#include "zippedbuffer.h"

#include <QDebug>

ZippedBuffer::ZippedBuffer()
{
}

void ZippedBuffer::write(QDataStream &stream)
{
    stream << this->_relativePath << this->_zippedData;
}

void ZippedBuffer::read(QDataStream &stream)
{
    stream >> this->_relativePath >> this->_zippedData;
}

void ZippedBuffer::setRelativePath(QString path)
{
    this->_relativePath = path;
}

QString ZippedBuffer::getRelativePath()
{
    return _relativePath;
}

void ZippedBuffer::setZippedData(QByteArray zippedData)
{
    this->_zippedData = zippedData;
}

QByteArray ZippedBuffer::getZippedData()
{
    return _zippedData;
}
