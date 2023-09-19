#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &Stopwatch::slotTimerAlarm);
}

Stopwatch::~Stopwatch() {}

QTime Stopwatch::look_time()
{
    return time_second;
}

void Stopwatch::slotTimerAlarm() {
    time_second = time_second.addMSecs(100);
    emit time_signal();
}

void Stopwatch::start() {
    timer->start(100);
    emit void time_signal_start();
}

void Stopwatch::stop() {
    timer->stop();
    emit void time_signal_start();
}

QTime Stopwatch::diff() {
    old_circle = new_circle;
    int second = old_circle.msecsTo(time_second);
    new_circle = time_second;
    diff_circle = null_time;
    diff_circle = diff_circle.addMSecs(second);
    return diff_circle;
}

void Stopwatch::clear() {
    time_second = null_time;
    old_circle = null_time;
    new_circle = null_time;
}
