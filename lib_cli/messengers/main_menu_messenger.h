#ifndef MAIN_MENU_MESSENGER_H
#define MAIN_MENU_MESSENGER_H

class MainMenuMessenger {
 public:
  static void ShowMainMenu();
  static void LogOutMessage();
  static void ShowQuitMenu();
  static void ShowIncorrectMenuInput();
  static void PressEnterToContinue();

 private:
  static const int kFrame = 45;
  static const int kDelay = 300;
};

#endif  // MAIN_MENU_MESSENGER_H
