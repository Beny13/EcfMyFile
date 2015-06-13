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
     * @param ecfFileName : chemin du fichier .ecf
     * @param folder : dossier dans lequel sera décompressé le fichier .ecf
     */
    void uncompress(const QString &ecfFileName, const QString &folder);
private:

    /**
     * @brief Méthode de création de dossier parent
     * @param filePath : chemin du fichier dont le dossier parent doit être créé
     */
    void createFileParentDirectories(QString filePath);

    /**
    * @brief _threadCount Nombre de threads utilisés pour la compression
    */
    int _threadCount;
};

#endif // EPSIFILECOMPRESSOR_H
