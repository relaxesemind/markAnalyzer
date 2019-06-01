#ifndef AREAMARKMODEL_H
#define AREAMARKMODEL_H

#include "Models/markmodel.h"

class AreaMarkModel : public MarkModel
{
public:
    AreaMarkModel() = default;
    virtual qreal function(const QImage &image, const QVector<QVector<bool> > &mask = QVector<QVector<bool> >())override;
    virtual QString markName()const override;
};

#endif // AREAMARKMODEL_H
