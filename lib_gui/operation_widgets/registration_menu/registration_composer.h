#ifndef REGISTRATION_COMPOSER_H
#define REGISTRATION_COMPOSER_H

#include <delta_size.h>
#include <geometry_composer.h>

class QWidget;
class QRect;
class RegistrationDescription;

class RegistrationComposer {
 public:
  DeltaSize ComposeDeltaSizeForDescription(
      const QRect& back_button_geometry,
      const DeltaSize& basic_delta_size) const;

 private:
};

#endif  // REGISTRATION_COMPOSER_H
