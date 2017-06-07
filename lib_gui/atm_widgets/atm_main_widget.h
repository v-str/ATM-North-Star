#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QMainWindow>

class QPaintEvent;
class QString;

namespace Ui {
class AtmMainWidget;
}

class AtmMainWidget : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmMainWidget(QWidget* parent = nullptr);
  ~AtmMainWidget();

  void SetAppearance(const QString& main_color = "black",
                     const QString& secondary_color = "grey",
                     const QString& additional_color = "blue");

 protected:
  virtual void resizeEvent(QResizeEvent* event);

 private:
  void SetFrameLayout();

  Ui::AtmMainWidget* ui = nullptr;
};

#endif  // ATM_MAIN_WIDGET_H
