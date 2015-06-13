#ifndef ZIPPER_H
#define ZIPPER_H
#include <QThread>
#include "filepool.h"
#include "zippedbufferpool.h"
#include "zippedbuffer.h"
#include <QFile>
#include <QDataStream>

/**
 * @brief La classe Zipper permet de compresser les fichiers
 */
class Zipper : public QThread
{
public:

    /**
     * @brief Constructeur de la classe Zipper
     * @param pool : FilePool contenant la liste de tous les fichiers à compresser
     * @param buffpool : ZippedBufferPool recevant les données compressées de chaque fichier du pool
     * @param rootpath : QString contenant le chemin du dossier depuis la racine
     */
    Zipper(FilePool &pool, ZippedBufferPool &buffpool, const QString& rootpath);

    /**
     * @brief Méthode run du Zipper qui récupère des fichiers du FilePool pour les compresser
     */
    virtual void run();
private:

    /**
     * @brief Méthode du Zipper permettant de compresser un fichier
     * @param filename : QString contenant le nom du fichier
     */
    void processFile(const QString &filename);

    /**
     * @brief _filepool Pool contenant les fichiers à compresser
     */
    FilePool &_filepool;

    /**
     * @brief _bufferpool Pool contenant les données des fichiers compressés
     */
    ZippedBufferPool &_bufferpool;

    /**
     * @brief _rootpath QString contenant le chemin du dossier à compresser depuis la racine
     */
    const QString& _rootpath;

};

#endif // ZIPPER_H
