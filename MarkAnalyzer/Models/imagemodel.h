#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include "Common/customtypes.h"
#include <QImage>
#include <QMap>
#include <QString>


class ImageModel
{
public:
    ImageModel() = default;

public: //property
    QImage image;
    ImageType type;
    QString path;
    QMap<QString,qreal> markValues; // string - mark name;
};

#endif // IMAGEMODEL_H
