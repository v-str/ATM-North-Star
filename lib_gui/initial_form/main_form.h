#ifndef MAIN_FORM_H
#define MAIN_FORM_H

#include <QMainWindow>
#include <QString>
#include <QTimer>

#include "text_color_swapper.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainForm(QWidget* parent = nullptr);
  ~MainForm();

 public slots:
  void ChangeTextColor();
  void ChangeTimeDate();

 private:
  void SetMainFormProperties();
  void SetConnections();
  void InitializeObjects();
  void RunTimers();

  Ui::MainForm* ui = nullptr;

  QTimer* color_timer_ = nullptr;
  QTimer* time_date_timer_ = nullptr;

  TextColorSwapper* color_swapper_ = nullptr;
};

#endif  // MAIN_FORM_H
