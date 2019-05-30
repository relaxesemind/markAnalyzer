#include "maxprobabilitymarkmodel.h"

qreal MaxProbabilityMarkModel::function(const QImage &image, const QVector<QVector<bool> > &mask)
{
    adjacencyMatrix_ g = this->getAdjacencyMatrix(image);

    qreal result = 0.0;

    this->adjMatrixForeach(g,[&](qreal value)
    {
        result = result < value ? value : result;
    });

    return result;
}

QString MaxProbabilityMarkModel::markName() const
{
    return "MPR - Максимальная вероятность";
}
