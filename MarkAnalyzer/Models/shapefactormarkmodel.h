#ifndef SHAPEFACTORMARKMODEL_H
#define SHAPEFACTORMARKMODEL_H


#include "Models/markmodel.h"


class ShapeFactorMarkModel : public MarkModel
{
public:
    ShapeFactorMarkModel() = default;

    virtual qreal function(const QImage &image, const QVector<QVector<bool> > &mask = QVector<QVector<bool> >())override;
    virtual QString markName()const override;
};

#endif // SHAPEFACTORMARKMODEL_H
