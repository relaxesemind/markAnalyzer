#ifndef CUSTOMTYPES_H
#define CUSTOMTYPES_H

#include <memory>
#include <Models/markmodel.h>

enum ImageType {
    melanoma = 0,
    notMelanoma = 1
};

using pMarkModel = std::shared_ptr<MarkModel>;

#endif // CUSTOMTYPES_H
