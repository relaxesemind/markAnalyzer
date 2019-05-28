#ifndef STATICSTORAGE_H
#define STATICSTORAGE_H


#include <QString>
#include <QVector>
#include <QMap>
#include <QImage>


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
    StaticStorage();

public:
   QVector<QImage> badImages, goodImages;



};

#endif // STATICSTORAGE_H
