#include "core.h"
#include "Models/seriamodel.h"
#include <QDebug>

void Core::loadImagesFromFolderPath(const QString &folderPath, ImageType type)
{
    SeriaModel seria(folderPath);
    auto files = seria.getFiles();
    auto& images = StaticStorage::shared().images;


    auto it = images.find(type);
    if (it == images.end())
    {
        images.insert(type,{});
    }

    auto& vector = *images.find(type);

     for (QString file : files)
     {
         QPixmap pix(file);
         if (!pix.isNull())
         {
            ImageModel image;
            image.image = pix.toImage();
            image.type = type;
            image.path = file;
            vector.append(image);
         }
         else
         {
             qDebug() << "null pix in void Core::loadImagesFromFolderPath \n folder = " << file;
         }
     }

}

void Core::calculateMarksForAllImages()
{
    auto& images = StaticStorage::shared().images;
    auto& marks = StaticStorage::shared().marks;

    std::for_each(images.begin(),images.end(),[&marks](QVector<ImageModel>& vector)
    {
        std::for_each(vector.begin(),vector.end(),[&marks](ImageModel& imageModel)
        {
            std::for_each(marks.begin(),marks.end(),[&imageModel](pMarkModel mark)
            {
                auto nude_mark = mark.get();
                imageModel.markValues.insert(nude_mark->markName(),nude_mark->function(imageModel.image));
            });
        });
    });
}
