#ifndef OPENCV_H
#define OPENCV_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include <QImage>
#include <QPixmap>
#include <QDebug>

inline cv::Mat QImageToCvMat( const QImage &inImage, bool inCloneImageData = true )
   {
      switch ( inImage.format() )
      {
         // 8-bit, 4 channel
         case QImage::Format_ARGB32:
         case QImage::Format_ARGB32_Premultiplied:
         {
            cv::Mat  mat( inImage.height(), inImage.width(),
                          CV_8UC4,
                          const_cast<uchar*>(inImage.bits()),
                          static_cast<size_t>(inImage.bytesPerLine())
                          );

            return (inCloneImageData ? mat.clone() : mat);
         }

         // 8-bit, 3 channel
         case QImage::Format_RGB32:
         {
            if ( !inCloneImageData )
            {
               qWarning() << "ASM::QImageToCvMat() - Conversion requires cloning so we don't modify the original QImage data";
            }

            cv::Mat  mat( inImage.height(), inImage.width(),
                          CV_8UC4,
                          const_cast<uchar*>(inImage.bits()),
                          static_cast<size_t>(inImage.bytesPerLine())
                          );

            cv::Mat  matNoAlpha;

            cv::cvtColor( mat, matNoAlpha, cv::COLOR_BGRA2BGR );   // drop the all-white alpha channel

            return matNoAlpha;
         }

         // 8-bit, 3 channel
         case QImage::Format_RGB888:
         {
            if ( !inCloneImageData )
            {
               qWarning() << "ASM::QImageToCvMat() - Conversion requires cloning so we don't modify the original QImage data";
            }

            QImage   swapped = inImage.rgbSwapped();

            return cv::Mat( swapped.height(), swapped.width(),
                            CV_8UC3,
                            const_cast<uchar*>(swapped.bits()),
                            static_cast<size_t>(swapped.bytesPerLine())
                            ).clone();
         }

         // 8-bit, 1 channel
         case QImage::Format_Indexed8:
         {
            cv::Mat  mat( inImage.height(), inImage.width(),
                          CV_8UC1,
                          const_cast<uchar*>(inImage.bits()),
                          static_cast<size_t>(inImage.bytesPerLine())
                          );

            return (inCloneImageData ? mat.clone() : mat);
         }

         default:
            qWarning() << "ASM::QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
            break;
      }

      return cv::Mat();
   }

inline cv::Mat QPixmapToCvMat( const QPixmap &inPixmap, bool inCloneImageData = true )
   {
      return QImageToCvMat( inPixmap.toImage(), inCloneImageData );
   }

#endif // OPENCV_H
