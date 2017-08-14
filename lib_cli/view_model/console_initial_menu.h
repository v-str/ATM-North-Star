#ifndef CONSOLE_VIEWER_H
#define CONSOLE_VIEWER_H

class MenuInputHandler;
class ConsoleLoginMenu;
class ConsoleDescriptionMenu;
class ConsoleRegistrationMenu;

class ConsoleInitialMenu {
 public:
  enum SubMenu { kExit, kLoginMenu, kRegistrationMenu, kDemoMenu };

  ConsoleInitialMenu();
  ~ConsoleInitialMenu();

  void RunInitialMenu();

  void RunLoginMenu();
  void RunRegistrationMenu();
  void RunDescriptionMenu();
  void DisplayFarewellMessage();

  int GetSubMenu() const;

 private:
  void RunSubMenu();

  void DisplaySplashScreen() const;
  void DisplayInitialMenu() const;

  bool IsInputContainSubMenu();

  MenuInputHandler* input_handler_ = nullptr;
  ConsoleLoginMenu* login_menu_ = nullptr;
  ConsoleRegistrationMenu* registration_menu_ = nullptr;
  ConsoleDescriptionMenu* description_menu_ = nullptr;

  int sub_menu_input_ = 0;
};

#endif  // CONSOLE_VIEWER_H
