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
class OperationFrame;

class DemoMenu : public QFrame {
  Q_OBJECT
 public:
  explicit DemoMenu(QWidget* parent = nullptr);
  ~DemoMenu();

  // same code
  void SetDeltaSize(const DeltaSize& delta_size);

 public slots:
  void ProcessBackButtonClick();
  void Show();

 signals:
  void BackButtonClicked();
  void PassGeometryForHide(const QRect&);
  void PassGeometryForExtrude(const QRect&);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  // same code
  void PaintWidgets();
  void SetFrameAnimation();

  void SetInitialGeometry();
  void SetScalingProperties();

  void SetConnections();

  AtmButton* back_button_ = nullptr;

  // same code
  AtmColorDesigner* color_designer_ = nullptr;
  OperationFrame* operation_frame_ = nullptr;

  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;
};

#endif  // DEMO_MENU_H
