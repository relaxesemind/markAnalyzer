#include "energymarkmodel.h"

qreal EnergyMarkModel::function(const QImage &image, const QVector<QVector<bool> > &mask)
{
    adjacencyMatrix_ g = this->getAdjacencyMatrix(image);

    qreal result = 0.0;

    this->adjMatrixForeach(g,[&](qreal value)
    {
        result += std::pow(value,2);
    });

    return result;
}

QString EnergyMarkModel::markName() const
{
    return "ASM - Энергия";
}
