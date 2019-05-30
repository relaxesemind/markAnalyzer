#ifndef MARKSCALCULATETASK_H
#define MARKSCALCULATETASK_H

#include <QObject>

class MarksCalculateTask : public QObject
{
    Q_OBJECT
public:
    explicit MarksCalculateTask(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MARKSCALCULATETASK_H