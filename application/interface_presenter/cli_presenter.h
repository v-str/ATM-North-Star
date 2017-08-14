#ifndef CLI_PRESENTER
#define CLI_PRESENTER

#include <memory>

#include <console_initial_menu.h>

class CLIPresenter {
 public:
  CLIPresenter();

  enum MenuPoints { kQuit, kDemo, kRegistration, kLogin };

  void RunApplication();

 private:
  void RunSubMenu(int sub_menu);

  std::unique_ptr<ConsoleInitialMenu> initial_menu_;
};

#endif  // CLI_PRESENTER
