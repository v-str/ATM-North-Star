#ifndef CONSOLE_VIEWER_H
#define CONSOLE_VIEWER_H

class MenuInputHandler;

class ConsoleViewer {
 public:
  enum MenuSubItems { kExit, kLoginMenu, kRegistrationMenu, kDemoMenu };

  ConsoleViewer();
  ~ConsoleViewer();

  void RunInitialMenuLoop();

  void DisplaySplashScreen() const;
  void DisplayInitialMenu() const;

 private:
  MenuInputHandler* input_handler_ = nullptr;

  int user_input_ = 0;
};

#endif  // CONSOLE_VIEWER_H
