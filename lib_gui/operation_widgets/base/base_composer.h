#ifndef BASE_COMPOSER_H
#define BASE_COMPOSER_H

#include <delta_size.h>
#include <geometry_composer.h>

class AtmButton;

class BaseComposer {
 public:
  void SetDeltaSize(const DeltaSize& delta_size);
  void ComposeBackButton(AtmButton* back_button);

 private:
  void SetBackButtonSettings();

  GeometryComposer back_button_composer_;
  DeltaSize delta_size_;
};

#endif  // BASE_COMPOSER_H
