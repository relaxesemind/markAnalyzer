#include "inertiamomentmarkmodel.h"

qreal InertiaMomentMarkModel::function(const QImage &image, const QVector<QVector<bool> > &mask)
{
    adjacencyMatrix_ g = this->getAdjacencyMatrix(image);

    qreal result = 0.0;

    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g.size(); ++j)
        {
            result += std::pow(i - j, 2) * g[i][j];
        }

    return result;
}

QString InertiaMomentMarkModel::markName() const
{
    return "CON - Момент инерции";
}
