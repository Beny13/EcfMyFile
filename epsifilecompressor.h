#ifndef EPSIFILECOMPRESSOR_H
#define EPSIFILECOMPRESSOR_H

#include "filepool.h"
#include "writer.h"

/**
 * @brief La classe EpsiFileCompressor gère la compression et la décompression d'un dossier
 */

class EpsiFileCompressor
{
public:
    /**
     * @brief Constructeur
     *
     * Constructeur vide de la classe EpsiFileCompressor
     */
    EpsiFileCompressor();

    /**
     * @brief Constructeur
     *
     * Constructeur de la classe EpsiFileCompressor
     *
     * @param threadCount : nombre de thread à utiliser pour la compression
     */
    EpsiFileCompressor(int threadCount);

    /**
     * @brief Méthode de compression d'un dossier
     * @param folder : chemin du dossier à compresser
     * @param ecfFileName : nom du fichier compressé
     */
    void compress(const QString &folder, const QString &ecfFileName);

    /**
     * @brief Méthode de décompression d'un fichier .ecf
     * @param size : taille souhaitée de l'explosion
     * @param position : position du centre sur l'écran
     */
    void uncompress(const QString &ecfFileName, const QString &folder);
private:
    void createFileParentDirectories(QString filePath);
    int _threadCount;
};

#endif // EPSIFILECOMPRESSOR_H
