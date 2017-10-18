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
  void ComposeFrame(QWidget* widget);
  void ComposeBackButton(QWidget* widget);

 private:
  void SetButtonComposer();

  GeometryComposer button_composer_;
  GeometryComposer frame_composer_;

  DeltaSize delta_size_;

  static constexpr double kButtonStretchX = 0.7;
  static constexpr double kButtonStretchY = 0.3;
};

#endif  // BASE_ATM_COMPOSER_H
