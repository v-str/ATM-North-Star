﻿#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QMainWindow>

#include <atm_color_designer.h>

class QPaintEvent;
class QString;
class WidgetColor;
class QTimer;

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

 public slots:
  void TimeDateTick();
  void MaximizeButtonClicked(bool);

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetConnections();
  void SetInitialSettings();
  void SetWidgetAppearance();
  void SetFrameLayout();
  void PaintWidgets();
  void InitializeObject();
  void RunTimers();

  Ui::AtmMainWidget* ui = nullptr;
  QTimer* timedate_timer_ = nullptr;

  AtmColorDesigner color_designer_;
};

#endif  // ATM_MAIN_WIDGET_H
