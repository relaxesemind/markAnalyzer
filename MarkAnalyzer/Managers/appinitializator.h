#ifndef APPINITIALIZATOR_H
#define APPINITIALIZATOR_H


#include <QObject>


class AppInitializator : public QObject
{
    Q_OBJECT
public:
    explicit AppInitializator();

signals:
    void appDidInitialize(bool);

public slots:
    void setupApplication();
};

#endif // APPINITIALIZATOR_H
