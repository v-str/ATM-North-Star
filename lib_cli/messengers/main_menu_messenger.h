#ifndef MAIN_MENU_MESSENGER_H
#define MAIN_MENU_MESSENGER_H

class MainMenuMessenger {
 public:
  static void ShowMainMenu();
  static void WishAGoodDay();
  static void ReRequestAboutExit();
  static void ShowQuitMenu();
  static void ShowIncorrectInput();
  static void ShowIncorrectMainMenuInput();
  static void ShowIncorrectRegistration();

 private:
  static constexpr int kFrame = 45;
};

#endif  // MAIN_MENU_MESSENGER_H
