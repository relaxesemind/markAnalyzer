#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Managers/appinitializator.h"
#include "Views/waitingspinnerwidget.h"

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_pushButton_5_clicked();

private:
    void setupUI();
    void loadNormalImages();
    void loadBadImages();

private:
    Ui::MainWindow *ui;
    QThreadPool *threadPool;
    WaitingSpinnerWidget *spinner;
};

#endif // MAINWINDOW_H
