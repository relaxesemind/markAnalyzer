#ifndef ENTROPYMARKMODEL_H
#define ENTROPYMARKMODEL_H


#include "Models/markmodel.h"

class EntropyMarkModel : public MarkModel
{
public:
    EntropyMarkModel() = default;

    virtual qreal function(const QImage &image, const QVector<QVector<bool> > &mask)override;
    virtual QString markName()const override;
};

#endif // ENTROPYMARKMODEL_H
