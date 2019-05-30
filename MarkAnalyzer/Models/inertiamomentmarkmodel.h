#ifndef INERTIAMOMENTMARKMODEL_H
#define INERTIAMOMENTMARKMODEL_H

#include "Models/markmodel.h"

class InertiaMomentMarkModel: public MarkModel
{
public:
    InertiaMomentMarkModel() = default;
    virtual qreal function(const QImage &image, const QVector<QVector<bool> > &mask)override;
    virtual QString markName()const override;
};

#endif // INERTIAMOMENTMARKMODEL_H
