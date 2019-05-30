#include "core.h"
#include "Models/seriamodel.h"
#include <QDebug>

void Core::loadImagesFromFolderPath(const QString &folderPath, ImageType type)
{
    SeriaModel seria(folderPath);
    auto files = seria.getFiles();

    auto it = StaticStorage::shared().images.find(type);
    if (it == StaticStorage::shared().images.end())
    {
        return;
    }
    auto& vector = *it;

     for (QString file : files)
     {
         QPixmap pix(file);
         if (!pix.isNull())
         {
            vector.append(pix.toImage());
         }
         else
         {
             qDebug() << "null pix in void Core::loadImagesFromFolderPath \n folder = " << file;
         }
     }

}
