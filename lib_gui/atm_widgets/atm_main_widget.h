#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QMainWindow>

class QPaintEvent;
class QString;

struct WidgetColor;

namespace Ui {
class AtmMainWidget;
}

class AtmMainWidget : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmMainWidget(QWidget* parent = nullptr);
  ~AtmMainWidget();

  void SetWidgetAppearance(const QString& main_color = "yellow",
                           const QString& secondary_color = "red",
                           const QString& additional_color = "blue");

 protected:
  virtual void resizeEvent(QResizeEvent* event);

 private:
  void SetUpWidgetProperties();
  void SetFrameLayout();
  void ColorizeButtons(const WidgetColor& widget_color);

  Ui::AtmMainWidget* ui = nullptr;
};

#endif  // ATM_MAIN_WIDGET_H
