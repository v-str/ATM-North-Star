#ifndef DESCRIPTION_MENU_GEOMETRY_H
#define DESCRIPTION_MENU_GEOMETRY_H

#include <QRect>

class DescriptionMenuGeometry {
 public:
  static QRect DescriptionMenu();
  static QRect BackButton();
  static QRect DescriprionFrame();

 private:
  static QRect kDescriptionMenu;
  static QRect kBackButton;

  static QRect kDescriptionFrame;
};

#endif  // DESCRIPTION_MENU_GEOMETRY_H
