#include "filepool.h"
#include <QDir>
#include <QMutexLocker>

FilePool::FilePool(const QString &folder)
{
    findFileInFolderAndSubfolders(folder);
}
void FilePool::findFileInFolderAndSubfolders(const QString &folder)
{
    QDir dir(folder);
    // list all the entries of the current folder
    foreach (const QFileInfo &entry,
             dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
        if( entry.isDir() == true )
        {
            // it is a folder, recursive call to fill the files_
            // member with the files contained in the subfolder
            findFileInFolderAndSubfolders(entry.filePath());
        }
        else if(entry.isFile() == true) {
            // it is a file with the right suffix,
            // Store it in the files_ member
            files_.append(entry.absoluteFilePath());
        }
    }
}
int FilePool::count() {
    QMutexLocker locker(&mutex_);
    return files_.size();
}

QString FilePool::tryGetFile() {
    QString file;
    // Début de d'exclusion mutuelle
    QMutexLocker locker(&mutex_);
    // Aucun autre thread ne peut exécuter ce code$
    // pour le moment
    if(files_.isEmpty() == false) {
        file = files_.front();
        files_.pop_front();
    }
    return file;
    // A la destruction de locker, les autres
    // threads pourront à nouveau essayer d'exécuter
    // ce code.
}
