#ifndef REGISTRATION_MENU_GEOMETRY_H
#define REGISTRATION_MENU_GEOMETRY_H

#include <QRect>

class RegistrationMenuGeometry {
 public:
  static QRect RegistrationFrame();
  static QRect DescriptionFrame();
  static QRect DesctiptionLabel();
  static QRect BackButton();

  static QRect CheckBoxOne();
  static QRect CheckBoxTwo();
  static QRect CheckBoxFrame();

 private:
  static QRect kRegistrationFrame;
  static QRect kDescriptionFrame;
  static QRect kDescriptionLabel;
  static QRect kBackButton;

  static QRect kCheckBoxOne;
  static QRect kCheckBoxTwo;

  static QRect kCheckBoxFrame;
};

#endif  // REGISTRATION_MENU_GEOMETRY_H
