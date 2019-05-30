#ifndef ENERGYMARKMODEL_H
#define ENERGYMARKMODEL_H


#include "Models/markmodel.h"


class EnergyMarkModel : public MarkModel
{
public:
    EnergyMarkModel() = default;

    virtual qreal function(const QImage &image, const QVector<QVector<bool> > &mask)override;
    virtual QString markName()const override;
};

#endif // ENERGYMARKMODEL_H
