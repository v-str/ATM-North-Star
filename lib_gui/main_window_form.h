#ifndef MAIN_WINDOW_FORM_H
#define MAIN_WINDOW_FORM_H

#include <QMainWindow>

namespace Ui {
class MainWindowForm;
}

class MainWindowForm : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindowForm(QWidget* parent = 0);
  ~MainWindowForm();

 private:
  Ui::MainWindowForm* ui;
};

#endif  // MAIN_WINDOW_FORM_H
