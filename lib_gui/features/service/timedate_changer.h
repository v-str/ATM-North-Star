#ifndef TIMEDATE_CHANGER_H
#define TIMEDATE_CHANGER_H

class QLabel;

class TimeDateChanger {
 public:
  static void ChangeDate(QLabel* date_widget);
  static void ChangeTime(QLabel* label_widget);
};

#endif  // TIMEDATE_CHANGER_H
