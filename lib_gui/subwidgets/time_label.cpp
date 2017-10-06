#include <time_label.h>

#include <QTimer>

TimeLabel::TimeLabel(QLabel *parent)
    : QLabel(parent), timer_(new QTimer(this)) {}

TimeLabel::~TimeLabel() { delete timer_; }
