#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

#include <QString>
#include <QByteArray>
#include <QDataStream>

/**
 * @brief La classe ZippedBuffer stocke les données compressées d'un fichier ainsi que son chemin
 */

class ZippedBuffer
{
public:

    /**
     * @brief Constructeur de la classe Writer
     */
    ZippedBuffer();

    /**
     * @brief Méthode d'écriture des données du fichier compressé dans un DataStream
     * @param stream : QDataStream dans lequel sera envoyé le chemin du fichier et ses données compressées
     */
    void write(QDataStream &stream);

    /**
     * @brief Méthode de lecture des données depuis un DataStream
     * @param stream : QDataStream depuis lequel sera récupéré le chemin du fichier compressé ainsi que ses données
     */
    void read(QDataStream &stream);

    /**
     * @brief Setter de l'attribut _relativePath
     * @param path : QString contenant le chemin relatif du fichier compressé
     */
    void setRelativePath(QString path);

    /**
     * @brief Guetter de l'attribut _relativePath
     * @return QString contenant le chemin relatif
     */
    QString getRelativePath();

    /**
     * @brief Setter de l'attribut _zippedData
     * @param zippedData : QByteArray contenant les données compressées
     */
    void setZippedData(QByteArray zippedData);

    /**
     * @brief Guetter de l'attribut _zippedData
     * @return QByteArray contenant les données du fichier compressé
     */
    QByteArray getZippedData();
private:

    /**
     * @brief _relativePath Chemin relatif du fichier à compresser
     */
    QString _relativePath;

    /**
     * @brief _zippedData Tableau des données compressées du fichier
     */
    QByteArray _zippedData;
};

#endif // ZIPPEDBUFFER_H
