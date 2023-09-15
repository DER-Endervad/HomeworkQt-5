#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFont>
#include <QTimer>
#include <QTime>

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

    void on_pB_clear_clicked();

    void on_pB_circle_clicked();

private:
    Ui::MainWindow *ui;
    int start_stop = 0;
    int cir_n = 1;
    QTimer *timer;
    QTime time_second = QTime(0,0,0);
    QTime old_circle = QTime(0,0,0);
    QTime new_circle = QTime(0,0,0);
    const QTime null_time = QTime(0,0,0);
};
#endif // MAINWINDOW_H
