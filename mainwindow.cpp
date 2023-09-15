#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pB_start_stop->setStyleSheet("color : green");
    ui->pB_circle->setEnabled(false);
    timer = new QTimer();
    ui->lE_time->setText(time_second.toString("hh:mm:ss"));
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimerAlarm);
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
        timer->start(1000);
        start_stop = 1;
    } else {
        ui->pB_start_stop->setText("Старт");
        ui->pB_start_stop->setStyleSheet("color : green");
        ui->pB_circle->setEnabled(false);
        timer->stop();
        start_stop = 0;
    }
}

void MainWindow::slotTimerAlarm()
{
    time_second = time_second.addSecs(1);
    ui->lE_time->setText(time_second.toString("hh:mm:ss"));
}


void MainWindow::on_pB_clear_clicked()
{
    time_second = null_time;
    ui->lE_time->setText(time_second.toString("hh:mm:ss"));
    ui->tE_circle->clear();
    cir_n = 1;
    old_circle = null_time;
}


void MainWindow::on_pB_circle_clicked()
{
    old_circle = new_circle;
    int second = old_circle.secsTo(time_second);
    new_circle = null_time;
    new_circle = new_circle.addSecs(second);
    ui->tE_circle->append("№"+QString::number(cir_n)+". Время круга: " + new_circle.toString("hh::mm::ss"));
    cir_n++;
    qDebug() << second;
    qDebug() << new_circle;
}

