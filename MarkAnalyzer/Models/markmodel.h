#ifndef MARKMODEL_H
#define MARKMODEL_H


#include <QString>
#include <QVector>
#include <QImage>
#include <array>
#include <functional>
#include <cmath>


using adjacencyMatrix_ = std::array<std::array<qreal,256>,256>;
using function_ = std::function<qreal (const QImage &image, const QVector<QVector<bool> > &mask)>;


class MarkModel
{
public:
    MarkModel() = default;

    virtual ~MarkModel(){}
    virtual qreal function(const QImage &image, const QVector<QVector<bool> > &mask);
    virtual QString markName();


protected:
   adjacencyMatrix_ getAdjacencyMatrix(const QImage& image);
   int brignessInPos(int xPos, int yPos, const QImage& image);

   template<class call> void adjMatrixForeach(adjacencyMatrix_ M, call object)
   {
       std::for_each(M.begin(),M.end(),[&](std::array<qreal,256> row)
       {
           std::for_each(row.begin(),row.end(),object);
       });

   }
};

#endif // MARKMODEL_H
