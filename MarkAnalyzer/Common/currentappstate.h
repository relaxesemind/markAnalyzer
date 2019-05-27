#ifndef CURRENTAPPSTATE_H
#define CURRENTAPPSTATE_H

#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfo>
#include "Models/seriamodel.h"


class CurrentAppState
{
public:
    CurrentAppState(CurrentAppState const&) = delete;
    CurrentAppState& operator=(CurrentAppState const&) = delete;
    static CurrentAppState& shared()
    {
        static CurrentAppState instance;
        return instance;
    }

private:
    CurrentAppState();

public:
   QString currentFilePath; // отображаемый на ImageView
   SeriaModel goodPhoto, badPhoto;
};

#endif // CURRENTAPPSTATE_H
