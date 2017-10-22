#ifndef REGISTRATION_COMPOSER_H
#define REGISTRATION_COMPOSER_H

#include <delta_size.h>
#include <geometry_composer.h>

class QWidget;
class QRect;
class RegistrationDescription;

class RegistrationComposer {
 public:
  RegistrationComposer();

  void ComposeRegistrationMenu(const DeltaSize& delta_size,
                               QWidget* registation_menu);

  DeltaSize ComposeDeltaSizeForDescription(
      const QRect& back_button_geometry,
      const DeltaSize& basic_delta_size) const;

 private:
  void SetDefaultComposingSettings();

  GeometryComposer composer_;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;
};

#endif  // REGISTRATION_COMPOSER_H
