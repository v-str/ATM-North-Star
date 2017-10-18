#ifndef BASE_ATM_COMPOSER_H
#define BASE_ATM_COMPOSER_H

#include <QWidget>

#include <atm_button.h>
#include <delta_size.h>
#include <geometry_composer.h>

class BaseAtmComposer {
 public:
  void SetDeltaSize(const DeltaSize& delta_size);
  void ComposeFrame(QWidget* widget);
  void ComposeBackButton(QWidget* widget);

 private:
  AtmButton button_composer_;
  AtmButton frame_composer_;

  DeltaSize delta_size_;
};

#endif  // BASE_ATM_COMPOSER_H
