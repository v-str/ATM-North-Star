#ifndef BASE_COMPOSER_H
#define BASE_COMPOSER_H

#include <delta_size.h>
#include <geometry_composer.h>

class BaseComposer {
 public:
 private:
  void SetBackButtonSettings();

  GeometryComposer back_button_composer_;
  GeometryComposer composer_;

  DeltaSize delta_size_;
};

#endif  // BASE_COMPOSER_H
