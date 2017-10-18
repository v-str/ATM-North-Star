#ifndef EXIT_DIALOG_GEOMETRY_H
#define EXIT_DIALOG_GEOMETRY_H

#include <QRect>

class ExitDialogGeometry {
 public:
  static QRect ExitDialog();
  static QRect ExitDialogFrame();
  static QRect ButtonYes();
  static QRect ButtonNo();
  static QRect MessageScreen();

 private:
  static QRect kExitDialog;
  static QRect kExitDialogFrame;
  static QRect kButtonYes;
  static QRect kButtonNo;
  static QRect kMessageScreen;
};

#endif  // EXIT_DIALOG_GEOMETRY_H
