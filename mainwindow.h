#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFont>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB_start_stop_clicked();
    void slotTimerAlarm();
    void slotTimerWatch();
    void on_pB_clear_clicked();
    void on_pB_circle_clicked();

private:
    Ui::MainWindow *ui;
    int start_stop = 0;
    int cir_n = 1;
    Stopwatch *watch;
};
#endif // MAINWINDOW_H
