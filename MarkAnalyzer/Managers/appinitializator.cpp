#include "appinitializator.h"
#include "Common/customtypes.h"

void AppInitializator::setupApplication()
{
    auto& marks = StaticStorage::shared().marks;
    marks = {
        std::make_shared<EnergyMarkModel>(),
        std::make_shared<EntropyMarkModel>(),
        std::make_shared<InertiaMomentMarkModel>(),
        std::make_shared<LocalUniformityMarkModel>(),
        std::make_shared<MaxProbabilityMarkModel>()
    };
}
