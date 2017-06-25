#include <timedate_changer.h>

#include <QDate>
#include <QLabel>
#include <QString>
#include <QTime>

void TimeDateChanger::ChangeDate(QLabel* date_widget) {
  QString date_string = QDate::currentDate().toString("dd.MM.yyyy");
  date_widget->setText(date_string);
}

void TimeDateChanger::ChangeTime(QLabel* label_widget) {
  QString time_string = QTime::currentTime().toString("hh:mm:ss");
  label_widget->setText(time_string);
}
