#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pB_start_stop->setStyleSheet("color : green");
    ui->pB_circle->setEnabled(false);
    watch = new Stopwatch(this);
    ui->lE_time->setText(watch->look_time().toString("hh:mm:ss.z"));
    connect(watch, &Stopwatch::time_signal_start, this, &MainWindow::slotTimerAlarm);
    connect(watch, &Stopwatch::time_signal, this, &MainWindow::slotTimerWatch);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_start_stop_clicked()
{
    if(start_stop == 0) {
        ui->pB_start_stop->setText("Стоп");
        ui->pB_start_stop->setStyleSheet("color : red");
        ui->pB_circle->setEnabled(true);
        watch->start();
        start_stop = 1;
    } else {
        ui->pB_start_stop->setText("Старт");
        ui->pB_start_stop->setStyleSheet("color : green");
        ui->pB_circle->setEnabled(false);
        watch->stop();
        start_stop = 0;
    }
}

void MainWindow::slotTimerAlarm()
{
    watch->slotTimerAlarm();
}

void MainWindow::slotTimerWatch()
{
    ui->lE_time->setText(watch->look_time().toString("hh:mm:ss.z"));
}


void MainWindow::on_pB_clear_clicked()
{
    watch->clear();
    ui->lE_time->setText(watch->look_time().toString("hh:mm:ss.z"));
    ui->tE_circle->clear();
    cir_n = 1;
}


void MainWindow::on_pB_circle_clicked()
{
    ui->tE_circle->append("№"+QString::number(cir_n)+". Время круга: " + watch->diff().toString("hh:mm:ss.z"));
    cir_n++;
}

