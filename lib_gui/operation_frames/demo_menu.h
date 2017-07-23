#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <QFrame>
#include <QObject>
#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>
#include <widget_hider.h>

class QWidget;
class AtmColorDesigner;
class AtmButton;

class DemoMenu : public QFrame {
  Q_OBJECT
 public:
  DemoMenu(QWidget* parent = nullptr);
  ~DemoMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 public slots:
  void ReturnToInitialMenu();
  void RememberGeometry();
  void Show();
  void Close();

 signals:
  void BackButtonClicked();
  void PassGeometry(const QRect&);
  void AlreadyClosed();

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void SetInitialGeometry();
  void PaintWidgets();
  void SetScalingProperties();
  void SetHidingAnimation();

  void SetConnections();

  AtmColorDesigner* color_designer_ = nullptr;
  AtmButton* back_button_ = nullptr;

  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  WidgetHider widget_hider_;
  DeltaSize delta_size_;
};

#endif  // DEMO_MENU_H
