#ifndef CONSOLE_VIEWER_H
#define CONSOLE_VIEWER_H

class MenuInputHandler;
class LoginMenu;
class ConsoleDemoMenu;
class RegistrationMenu;

class ConsoleViewer {
 public:
  enum SubMenu { kExit, kLoginMenu, kRegistrationMenu, kDemoMenu };

  ConsoleViewer();
  ~ConsoleViewer();

  void RunView();

  void RunLoginMenu();
  void RunRegistrationMenu();
  void RunDemoMenu();
  void DisplayFarewellMessage();

  int GetSubMenu() const;

 private:
  void RunSubMenu();

  void DisplaySplashScreen() const;
  void DisplayInitialMenu() const;

  bool IsInputContainSubMenu();

  MenuInputHandler* input_handler_ = nullptr;
  LoginMenu* login_menu_ = nullptr;
  RegistrationMenu* registration_menu_ = nullptr;
  ConsoleDemoMenu* demo_menu_ = nullptr;

  int sub_menu_input_ = 0;
};

#endif  // CONSOLE_VIEWER_H
