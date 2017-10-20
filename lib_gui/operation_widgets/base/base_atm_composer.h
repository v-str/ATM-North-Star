#ifndef BASE_ATM_COMPOSER_H
#define BASE_ATM_COMPOSER_H

#include <QWidget>

#include <atm_button.h>
#include <delta_size.h>
#include <geometry_composer.h>

class BaseAtmComposer {
 public:
  BaseAtmComposer();

  void SetDeltaSize(const DeltaSize& delta_size);
  void ComposeFrame(const QRect& frame_geometry, QWidget* widget);
  void ComposeBackButton(const QRect& button_geometry, QWidget* widget);

 private:
  void SetButtonComposer();
  void SetFrameComposer();

  GeometryComposer button_composer_;
  GeometryComposer frame_composer_;

  static constexpr double kButtonStretchX = 0.7;
  static constexpr double kButtonStretchY = 0.3;
  static constexpr double kButtonShiftX = 0.0;
  static constexpr double kButtonShiftY = 1.0;

  static constexpr double kFrameStretchX = 1.0;
  static constexpr double kFrameStretchY = 1.0;
};

#endif  // BASE_ATM_COMPOSER_H
