#ifndef LOCALUNIFORMITYMARKMODEL_H
#define LOCALUNIFORMITYMARKMODEL_H

#include "Models/markmodel.h"

class LocalUniformityMarkModel : public MarkModel
{
public:
    LocalUniformityMarkModel() = default;

    virtual qreal function(const QImage &image, const QVector<QVector<bool> > &mask = QVector<QVector<bool> >())override;
    virtual QString markName()const override;
};

#endif // LOCALUNIFORMITYMARKMODEL_H
