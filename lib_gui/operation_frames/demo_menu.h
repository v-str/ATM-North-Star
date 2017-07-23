#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <QFrame>
#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

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

 signals:
  void BackButtonClicked();
  void PassGeometry(const QRect&);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void SetInitialGeometry();
  void PaintWidgets();
  void SetScalingProperties();

  void SetConnections();

  AtmColorDesigner* color_designer_ = nullptr;
  AtmButton* back_button_ = nullptr;

  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;
};

#endif  // DEMO_MENU_H
