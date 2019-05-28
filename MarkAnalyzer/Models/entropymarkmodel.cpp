#include "entropymarkmodel.h"

qreal EntropyMarkModel::function(const QImage &image, const QVector<QVector<bool> > &mask)
{
    adjacencyMatrix_ g = this->getAdjacencyMatrix(image);

    qreal result = 0.0;

    this->adjMatrixForeach(g,[&](qreal value)
    {
        result += value * std::log(value);
    });

    return -result;
}

QString EntropyMarkModel::markName()
{
    return "ENT - Энтропия";
}
