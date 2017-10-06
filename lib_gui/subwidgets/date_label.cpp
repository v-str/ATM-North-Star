#include <date_label.h>

#include <QTimer>

DateLabel::DateLabel(QLabel *parent)
    : QLabel(parent), timer_(new QTimer(this)) {}

DateLabel::~DateLabel() { delete timer_; }
