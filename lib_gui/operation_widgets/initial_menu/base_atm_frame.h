#ifndef BASE_ATM_FRAME_H
#define BASE_ATM_FRAME_H

#include <QFrame>
#include <QList>
#include <QObject>
#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class AtmButton;
class AtmFrameSetter;
class QWidget;
class QPushButton;

class BaseAtmFrame : public QFrame {
  Q_OBJECT
 public:
  enum BackButtonCondition { kBackButtonActivated, kBackButtonDeactivated };

  explicit BaseAtmFrame(
      QWidget* parent = nullptr,
      BackButtonCondition back_button_condition = kBackButtonActivated);
  ~BaseAtmFrame();

  void SetDeltaSize(const DeltaSize& delta_size);
  void SetInitialFrameGeometry(const QRect& geometry);
  void SetInitialBackButtonGeometry(const QRect& geometry);
  void SetFrameAnimation(unsigned int hide_to,
                         unsigned int extrude_from,
                         unsigned int duration_msec,
                         QFrame* animated_frame);

  void ColorizeButtons(const QList<QPushButton*>& button_list);

 public slots:
  void ProcessBackButtonClick();
  void Show();

 signals:
  void BackButtonClicked();
  void PassGeometryForHide(const QRect&);
  void PassGeometryForExtrude(const QRect&);

 protected:
  void ScaleBackButton();

 private:
  void ColorizeBackButton();
  void SetBasicConnections();
  void SetBackButtonScaling();

  AtmButton* back_button_ = nullptr;
  AtmFrameSetter* frame_setter_ = nullptr;

  QRect initial_frame_geometry_;
  QRect initial_back_button_geometry_;

  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;

  static constexpr double kXShiftFactor = 0.0;
  static constexpr double kYShiftFactor = 1.0;
  static constexpr double kXStretchFactor = 0.07;
  static constexpr double kYStretchFactor = 0.03;
};

#endif  // BASE_ATM_FRAME_H
