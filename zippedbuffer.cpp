#include "zippedbuffer.h"

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
