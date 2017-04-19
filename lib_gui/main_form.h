#ifndef MAIN_FORM_H
#define MAIN_FORM_H

#include <QMainWindow>

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainForm(QWidget* parent = nullptr);
  ~MainForm();

 private:
  Ui::MainForm* ui = nullptr;
};

#endif  // MAIN_FORM_H
