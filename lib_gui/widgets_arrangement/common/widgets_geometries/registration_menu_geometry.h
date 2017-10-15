#ifndef REGISTRATION_MENU_GEOMETRY_H
#define REGISTRATION_MENU_GEOMETRY_H

#include <QRect>

class RegistrationMenuGeometry {
 public:
  static QRect RegistrationFrame();
  static QRect DescriptionFrame();
  static QRect NextButton();
  static QRect BackButton();

 private:
  static QRect kRegistrationFrame;
  static QRect kDescriptionFrame;
  static QRect kNextButton;
  static QRect kBackButton;
};

#endif  // REGISTRATION_MENU_GEOMETRY_H
