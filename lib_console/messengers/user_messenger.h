#ifndef USER_MESSANGER_H
#define USER_MESSANGER_H

class UserMessenger {
 public:
  void ShowMainMenu();

  void WishAGoodDay() const;
  void ShowMainMenu() const;

  void ReRequestAboutExit() const;

  void SuggestToExit() const;
  void ShowIncorrectInput() const;
  void ShowIncorrectMainMenuInput() const;

  void ShowIncorrectRegisterData() const;

 private:
  static constexpr int kFrame = 45;
};

#endif  // USER_MESSANGER_H
