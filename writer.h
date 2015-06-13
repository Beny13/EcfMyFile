#ifndef WRITER_H
#define WRITER_H

#include <QString>
#include <QThread>

#include "zippedbufferpool.h"

/**
 * @brief La classe Writer représente l'entité qui va créer le fichier compressé .ecf
 */
class Writer : public QThread
{
Q_OBJECT
public:

    /**
     * @brief Constructeur de la classe Writer
     * @param pool : ZipperBufferPool contenant la totalité des fichiers compressés
     * @param destination : Chemin de destination du fichier .ecf
     */
    Writer(ZippedBufferPool& pool, const QString &destination);

    /**
     * @brief Fonction run() du Writer permettant de prendre toutes les données
     * du ZippedBufferPool
     */
    virtual void run();
private:

    /**
     * @brief _pool ZippedBufferPool dans laquelle sont stockées les données des
     * fichiers compressés
     */
    ZippedBufferPool& _pool;

    /**
     * @brief _destination Chemin de destination où sera créer le fichier .ecf
     */
    const QString& _destination;
};

#endif // WRITER_H
