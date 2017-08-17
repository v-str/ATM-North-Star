#ifndef CONSOLE_VIEWER_H
#define CONSOLE_VIEWER_H

#include <string>

#include <console_description_menu.h>
#include <console_initial_menu.h>
#include <console_login_menu.h>
#include <console_registration_menu.h>

class ConsoleViewer {
 public:
  enum MenuItem { kQuit, kDemo, kRegistration, kLogin };

  void DisplaySplashScreen();
  void RunInitialMenu();
  void DisplayFarewellMessage();

  std::string LoginString() const;
  std::string PasswordString() const;

  bool IsUserWantToExit() const;
  bool IsRegistrationDataReceived() const;

 protected:
  void RunSubMenu(int sub_menu);
  void RunDescriptionMenu();
  void RunRegistrationMenu();

 private:
  ConsoleInitialMenu initial_menu_;
  ConsoleLoginMenu login_menu_;
  ConsoleDescriptionMenu description_menu_;
  ConsoleRegistrationMenu registration_menu_;

  bool user_want_exit_ = false;
  bool is_registration_data_received_ = false;
};

#endif  // CONSOLE_VIEWER_H
