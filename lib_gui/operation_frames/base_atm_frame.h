#ifndef BASE_ATM_FRAME_H
#define BASE_ATM_FRAME_H

#include <QFrame>
#include <QObject>
#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class AtmButton;
class OperationFrame;
class QWidget;

class BaseAtmFrame : public QFrame {
  Q_OBJECT
 public:
  explicit BaseAtmFrame(QWidget* parent = nullptr);
  ~BaseAtmFrame();

  void SetDeltaSize(const DeltaSize& delta_size);
  void SetInitialFrameGeometry(const QRect& geometry);
  void SetBackButtonGeometry(const QRect& geometry);
  void SetFrameAnimation(unsigned int hide_to,
                         unsigned int extrude_from,
                         unsigned int duration_msec,
                         QFrame* animated_frame);

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
  void ColorizeBackButton();
  void SetConnections();
  void SetBackButtonScaling();

  AtmButton* back_button_ = nullptr;
  OperationFrame* operation_frame_ = nullptr;

  QRect initial_frame_geometry_;
  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;
};

#endif  // BASE_ATM_FRAME_H
