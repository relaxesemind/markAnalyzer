#ifndef MARKSCALCULATETASK_H
#define MARKSCALCULATETASK_H


#include <QObject>
#include <QRunnable>


class MarksCalculateTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit MarksCalculateTask(QObject *parent = nullptr);

protected:
    void run();

signals:
    void processPercent(int);
    void isDone(bool);
    void isRunning(bool);


public slots:

};

#endif // MARKSCALCULATETASK_H
