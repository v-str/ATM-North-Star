#ifndef CONSOLE_VIEWER_H
#define CONSOLE_VIEWER_H

class MenuInputHandler;

class ConsoleViewer {
 public:
  enum SubMenu { kExit, kLoginMenu, kRegistrationMenu, kDemoMenu };

  ConsoleViewer();
  ~ConsoleViewer();

  void RunView();

 private:
  void RunSubMenu();

  void DisplaySplashScreen() const;
  void DisplayInitialMenu() const;

  bool IsInputContainSubMenu();

  MenuInputHandler* input_handler_ = nullptr;

  int sub_menu_input_ = 0;
};

#endif  // CONSOLE_VIEWER_H
