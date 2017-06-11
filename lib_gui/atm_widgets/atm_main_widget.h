#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QMainWindow>

#include <atm_color_designer.h>

class QPaintEvent;
class QString;
class WidgetColor;

namespace Ui {
class AtmMainWidget;
}

class AtmMainWidget : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmMainWidget(QWidget* parent = nullptr);
  ~AtmMainWidget();

  void SetWidgetAppearance(const QString& main_color,
                           const QString& secondary_color,
                           const QString& additional_color);

  void SetBackgroundColor(const QString& background_color);

 protected:
  virtual void resizeEvent(QResizeEvent* event);

 private:
  void SetUpWidgetProperties();
  void SetFrameLayout();
  void PaintWidgets();

  Ui::AtmMainWidget* ui = nullptr;

  AtmColorDesigner color_designer_;
};

#endif  // ATM_MAIN_WIDGET_H
