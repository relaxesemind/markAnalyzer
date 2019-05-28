#include "markmodel.h"

int MarkModel::brignessInPos(int xPos, int yPos, const QImage &image)
{
    QRgb pixel = image.pixel(xPos,yPos);
    return (qRed(pixel) + qBlue(pixel) + qGreen(pixel)) / 3;
}

qreal MarkModel::function(const QImage &image, const QVector<QVector<bool> > &mask)
{
    return 0.0;
}

QString MarkModel::markName()
{
    return "default mark";
}

adjacencyMatrix_ MarkModel::getAdjacencyMatrix(const QImage &image)
{
    std::array<std::array<int,256>,256> G = std::array<std::array<int,256>,256>();
    adjacencyMatrix_ g = adjacencyMatrix_();

    const int h = image.height();
    const int w = image.width();
    const int size = h * w;

    for(qint32 y = 0; y < h; ++y) {
      for(qint32 x = 0; x < w - 1; ++x) {
          int i = brignessInPos(x, y,image);
          int j = brignessInPos(x + 1, y,image);
          ++G[i][j];

      //    std::cout<<G[i][j]<<" ";
        }
    //  std::cout<<std::endl;
    }

    for(qint32 i = 0; i < 255; ++i)
      for(qint32 j = 0; j < 255; ++j) {
          g[i][j] = static_cast<qreal> (G[i][j]) / (size);
      }

    return g;
}


