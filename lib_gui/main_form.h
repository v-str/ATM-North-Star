#ifndef MAIN_FORM_H
#define MAIN_FORM_H

#include <QMainWindow>
#include <QString>
#include <QTimer>

#include "running_text.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainForm(QWidget* parent = nullptr);
  ~MainForm();

 public slots:
  void ChangeColor();
  void RunText();

 private:
  void SetMainFormProperties();
  void SetConnections();
  void ChangeTextColor(QWidget* widget, const QString& text_color, bool state);
  void InitializeObjects();
  void RunTimers();

  Ui::MainForm* ui = nullptr;
  QTimer* color_timer_ = nullptr;
  QTimer* running_text_timer_ = nullptr;

  RunningText* running_text_;

  bool is_state_changed_ = false;
};

#endif  // MAIN_FORM_H
