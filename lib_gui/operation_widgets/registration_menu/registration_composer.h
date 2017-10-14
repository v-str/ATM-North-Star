#ifndef REGISTRATION_COMPOSER_H
#define REGISTRATION_COMPOSER_H

#include <delta_size.h>
#include <geometry_composer.h>

class QWidget;

class RegistrationComposer {
 public:
  RegistrationComposer();

  void ComposeGeometry(const DeltaSize& delta_size,
                       QWidget* widget_for_compose);

 private:
  void SetDefaultComposingSettings();

  GeometryComposer composer_;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;
};

#endif  // REGISTRATION_COMPOSER_H
