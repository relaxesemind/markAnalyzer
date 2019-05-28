#include "appinitializator.h"

void AppInitializator::setupApplication()
{
    auto& marks = StaticStorage::shared().marks;
    marks = {
        EnergyMarkModel(),
        EntropyMarkModel(),
        InertiaMomentMarkModel(),
        LocalUniformityMarkModel()
    };
}
