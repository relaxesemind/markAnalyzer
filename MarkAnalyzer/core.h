#ifndef CORE_H
#define CORE_H

#include "Common/magic.h"
#include "Common/staticstorage.h"

#include <QObject>


class Core : public QObject
{
    Q_OBJECT
    MakeSingletonFromClass(Core)

public:


signals:

public slots:
        void loadImagesFromFolderPath(const QString& folderPath, ImageType type);
        void calculateMarksForAllImages();


private:

};

#endif // CORE_H
