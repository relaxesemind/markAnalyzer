#include "shapefactormarkmodel.h"


qreal ShapeFactorMarkModel::function(const QImage &image, const QVector<QVector<bool> > &mask)
{
    if (mask.isEmpty())
    {
        return 0.0;
    }

   #warning TODO - openCV

    return 1;
}

QString ShapeFactorMarkModel::markName() const
{
    return "SHF - Коэффициент Формы";
}
