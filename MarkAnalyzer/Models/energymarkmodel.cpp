#include "energymarkmodel.h"

qreal EnergyMarkModel::function(const QImage &image, const QVector<QVector<bool> > &mask)
{
    adjacencyMatrix_ g = this->getAdjacencyMatrix(image);

    qreal result = 0.0;

    this->adjMatrixForeach(g,[&](qreal value)
    {
        result += value * value;
    });

    return result;
}

QString EnergyMarkModel::markName()
{
    return "ASM - Энергия";
}
