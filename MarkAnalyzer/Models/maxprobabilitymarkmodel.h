#ifndef MAXPROBABILITYMARKMODEL_H
#define MAXPROBABILITYMARKMODEL_H

#include "Models/markmodel.h"

class MaxProbabilityMarkModel : public MarkModel
{
public:
    MaxProbabilityMarkModel() = default;

    virtual qreal function(const QImage &image, const QVector<QVector<bool> > &mask = QVector<QVector<bool> >())override;
    virtual QString markName()const override;
};

#endif // MAXPROBABILITYMARKMODEL_H
