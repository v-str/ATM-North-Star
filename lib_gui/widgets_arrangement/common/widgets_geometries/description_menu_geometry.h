#ifndef DESCRIPTION_MENU_GEOMETRY_H
#define DESCRIPTION_MENU_GEOMETRY_H

#include <QRect>

class DescriptionMenuGeometry {
 public:
  static QRect DescriptionMenu();
  static QRect BackButton();
  static QRect DescriprionFrame();
  static QRect DescriprionLabel();
  static QRect DescriptionTitle();

 private:
  static QRect kDescriptionMenu;
  static QRect kBackButton;

  static QRect kDescriptionFrame;
  static QRect kDescriptionLabel;
  static QRect kDescriptionTitle;
};

#endif  // DESCRIPTION_MENU_GEOMETRY_H
