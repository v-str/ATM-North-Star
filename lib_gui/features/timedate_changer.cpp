#include "timedate_changer.h"

#include <QDate>
#include <QString>
#include <QTime>

void TimeDateChanger::ChangeTimeData(QLabel* widget) {
  QString current_data = QDate::currentDate().toString("dd.MM.yyyy") + "   " +
                         QTime::currentTime().toString("hh:mm:ss");
  widget->setText(current_data);
}
