#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <QFrame>
#include <QObject>
#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class QWidget;
class AtmColorDesigner;
class AtmButton;
class FrameAnimator;

class DemoMenu : public QFrame {
  Q_OBJECT
 public:
  explicit DemoMenu(QWidget* parent = nullptr);
  ~DemoMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 public slots:
  void ProcessBackButtonClick();
  void Show();

 signals:
  void BackButtonClicked();
  void PassGeometryForHide(const QRect&);
  void PassGeometryForExtrude(const QRect&);
  void AlreadyClosed();

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void SetInitialGeometry();
  void PaintWidgets();
  void SetScalingProperties();
  void SetFrameAnimation();

  void SetConnections();

  AtmColorDesigner* color_designer_ = nullptr;
  AtmButton* back_button_ = nullptr;
  FrameAnimator* hide_animator_ = nullptr;
  FrameAnimator* extrude_animator_ = nullptr;

  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;
};

#endif  // DEMO_MENU_H
