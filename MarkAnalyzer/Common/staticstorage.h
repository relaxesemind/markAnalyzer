#ifndef STATICSTORAGE_H
#define STATICSTORAGE_H

#include "Models/markmodels.h"
#include "Common/customtypes.h"

#include <QString>
#include <QVector>
#include <QMap>
#include <QImage>
#include <memory>


class StaticStorage
{
public:
    StaticStorage(StaticStorage const&) = delete;
    StaticStorage& operator=(StaticStorage const&) = delete;
    static StaticStorage& shared()
    {
        static StaticStorage instance;
        return instance;
    }

private:
    StaticStorage() = default;

public:
   QMap<ImageType,QVector<QImage>> images;
   QVector<pMarkModel> marks;
};

#endif // STATICSTORAGE_H
