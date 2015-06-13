#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H

#include <QMutex>
#include <QWaitCondition>
#include "zippedbuffer.h"

/**
 * @brief La classe ZippedBufferPool permet de créer un pool contenant la totalité des données des fichiers compressés d'un répertoire
 */

class ZippedBufferPool
{
public:

    /**
     * @brief Constructeur
     *
     * Constructeur vide de la classe EpsiFileCompressor
     */
    ZippedBufferPool();

    /**
     * @brief tryGet récupère une fichier compressé dans le ZippedBufferPool sous la forme d'un QPair
     * @return Un QPair contenant un boolean assurant la véracité des informations et un ZippedBuffer associé au fichier compressé
     */
    QPair<bool,ZippedBuffer> tryGet();

    /**
     * @brief Permet d'ajouter un ZippedBuffer dans le ZippedBufferPool
     * @param zb : ZippedBuffer à ajouter dans le ZippedBufferPool
    */
    void put(ZippedBuffer zb);

    /**
     * @brief Cette méthode est appelée pour indiquer que la totalité du dossier à compresser se trouve dans le ZippedBufferPool
    */
    void done();
private:

    /**
     * @brief _pool : liste de tous les ZippedBuffer associés à tous les fichiers du répertoire à compresser
     */
    QList<ZippedBuffer> _pool;

    /**
     * @brief _cond : Condition pour attendre que le pool soit rempli
     */
    QWaitCondition _cond;

    /**
     * @brief _mutex : Mutex permettant de synchroniser l'accès au pool de ZippedBuffer
     */
    QMutex _mutex;

    /**
     * @brief _done : Booléen indiquant si le ZippedBufferPool a reçu toutes les données compressées du dossier cible et spécifiant au Writer de s'arrêter
     */
    bool _done;
};

#endif // ZIPPEDBUFFERPOOL_H
