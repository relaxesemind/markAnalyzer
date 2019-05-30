#include "markscalculatetask.h"
#include "core.h"

MarksCalculateTask::MarksCalculateTask(QObject *parent) : QObject(parent)
{

}

void MarksCalculateTask::run()
{
    emit isRunning(true);

    Core::shared().calculateMarksForAllImages();

    emit isRunning(false);
    emit isDone(true);
}
