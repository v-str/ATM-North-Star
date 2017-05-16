#ifndef QUIT_MENU_HANDLER_H
#define QUIT_MENU_HANDLER_H

class QuitMenuHandler {
 public:
  static bool GetQuitResult();

 private:
  static void GetValueFromUser();

  static constexpr int kQuit = 0;
  static constexpr int kMainMenu = 1;
  static constexpr int kSumMenuQuit = 2;
};

#endif  // QUIT_MENU_HANDLER_H
