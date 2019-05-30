#include "localuniformitymarkmodel.h"

qreal LocalUniformityMarkModel::function(const QImage &image, const QVector<QVector<bool> > &mask)
{
    adjacencyMatrix_ g = this->getAdjacencyMatrix(image);

    qreal result = 0.0;

    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g.size(); ++j)
        {
            result += g[i][j] / (1 + std::pow(i - j, 2));
        }

    return result;
}

QString LocalUniformityMarkModel::markName() const
{
    return "LUN - Локальная однородность";
}
