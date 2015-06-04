#ifndef WRITER_H
#define WRITER_H

#include <QList>
#include <QString>
#include <QMutex>
#include <QByteArray>

class Writer
{
public:
    Writer(QString destination);
    void createFile();
    void tryStoreByteArray(QByteArray compressedDatas, QString filename);

private:
    QString _filename;
    QList<QByteArray> _compressedDatas;
    QList<QString> _filesnames;
    QMutex _mutex;
};

#endif // WRITER_H
