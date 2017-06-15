#include "timedate_changer.h"

#include <QDate>
#include <QString>
#include <QTime>

void TimeDateChanger::ChangeTimeData(QLabel* widget) {
  QString timedate = QDate::currentDate().toString("dd.MM.yyyy") + "  " +
                     QTime::currentTime().toString("hh:mm:ss");
  widget->setText(timedate);
}
