#ifndef APPINITIALIZATOR_H
#define APPINITIALIZATOR_H


#include "Models/markmodels.h"
#include "Common/staticstorage.h"
#include "Common/settingsstorage.h"


class AppInitializator
{
public:
    AppInitializator(AppInitializator const&) = delete;
    AppInitializator& operator=(AppInitializator const&) = delete;
    static AppInitializator& shared()
    {
        static AppInitializator instance;
        return instance;
    }

private:
    AppInitializator() = default;

public:
    void setupApplication();
};

#endif // APPINITIALIZATOR_H
