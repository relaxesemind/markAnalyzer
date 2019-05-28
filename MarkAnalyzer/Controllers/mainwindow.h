#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Managers/appinitializator.h"

#include <QMainWindow>
#include <QThreadPool>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUI();

private:
    Ui::MainWindow *ui;
    QThreadPool threadPool;
};

#endif // MAINWINDOW_H
