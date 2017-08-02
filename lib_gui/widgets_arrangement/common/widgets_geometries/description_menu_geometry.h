#ifndef DESCRIPTION_MENU_GEOMETRY_H
#define DESCRIPTION_MENU_GEOMETRY_H

#include <QRect>

class DescriptionMenuGeometry {
 public:
  static QRect DescriptionMenu();
  static QRect BackButton();
  static QRect DescriprionFrame();
  static QRect DescriprionLabel();

 private:
  static QRect kDescriptionMenu;
  static QRect kBackButton;

  static QRect kDescriptionFrame;
  static QRect kDescriptionLabel;
};

#endif  // DESCRIPTION_MENU_GEOMETRY_H
