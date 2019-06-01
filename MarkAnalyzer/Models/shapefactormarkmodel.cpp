#include "shapefactormarkmodel.h"

#include <vector>
#include "Common/opencv.h"

qreal ShapeFactorMarkModel::function(const QImage &image, const QVector<QVector<bool> > &mask)
{
    if (image.isNull())
    {
        return 0.0;
    }

    cv::Mat src = QImageToCvMat(image);
    cv::Mat bw;

     for( int x = 0; x < src.rows; x++ )
     {
       for( int y = 0; y < src.cols; y++ )
       {
           if ( src.at<cv::Vec3b>(x, y) == cv::Vec3b(255,255,255) )
           {
             src.at<cv::Vec3b>(x, y)[0] = 0;
             src.at<cv::Vec3b>(x, y)[1] = 0;
             src.at<cv::Vec3b>(x, y)[2] = 0;
           }
         }
     }

    cv::cvtColor(src, bw, CV_BGR2GRAY);
    cv::threshold(bw, bw, 110, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(bw, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

    cv::Mat src2 = QImageToCvMat(image);
    cv::drawContours(src2, contours, -1, cv::Scalar(255,0,0), 3, cv::LINE_4, hierarchy, 3);

    double k = 0;
    if (!contours.empty())
    {
       double p = cv::arcLength(contours[0],true);
       double s = cv::contourArea(contours[0],false);
       k = 100 * (p/(s + 0.01));
    }

    return k;
}

QString ShapeFactorMarkModel::markName() const
{
    return "SHF - Коэффициент Формы";
}
