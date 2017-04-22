#ifndef MAIN_FORM_H
#define MAIN_FORM_H

#include <QMainWindow>
#include <QString>
#include <QTimer>

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

 private:
  void SetWidgetProperties();
  void SetConnections();

  void ChangeTextColor(QWidget* widget, const QString& text_color, bool state);

  Ui::MainForm* ui = nullptr;
  QTimer* timer_ = nullptr;

  bool is_state_changed_ = false;
};

#endif  // MAIN_FORM_H
