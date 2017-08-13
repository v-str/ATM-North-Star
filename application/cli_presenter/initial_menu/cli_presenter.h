#ifndef CLI_PRESENTER
#define CLI_PRESENTER

#include <demo_menu.h>
#include <menu_input_handler.h>
#include <registrator.h>

class CLIPresenter {
 public:
  enum MenuPoints { kQuit, kDemo, kRegistration, kLogin };

  void RunApplication();

  int UserChoice() const;

 private:
  void RunApplicationLoop();
  void RunDemoMode();
  void RunRegistration();

  MenuInputHandler quit_handler_;
  DemoMenu demo_mode_;
  Registrator registrator_;

  int user_choice_ = 0;
};

#endif  // CLI_PRESENTER
