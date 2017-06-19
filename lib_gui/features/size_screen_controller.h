#ifndef SIZE_SCREEN_CONTROLLER_H
#define SIZE_SCREEN_CONTROLLER_H

class QMainWindow;

class SizeScreenController {
 public:
  static void SetFullScreen(QMainWindow* widget);
  static void SetNormalScreen(QMainWindow* widget);

  static bool IsFullScreen();

 private:
  static bool is_full_screen_;
};

#endif  // SIZE_SCREEN_CONTROLLER_H
