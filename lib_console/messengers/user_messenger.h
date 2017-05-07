#ifndef USER_MESSANGER_H
#define USER_MESSANGER_H

class UserMessenger {
 public:
  static void ShowMainMenu();
  static void WishAGoodDay();
  static void ReRequestAboutExit();
  static void SuggestToExit();
  static void ShowIncorrectInput();
  static void ShowIncorrectMainMenuInput();
  static void ShowIncorrectRegisterData();

 private:
  static constexpr int kFrame = 45;
};

#endif  // USER_MESSANGER_H
