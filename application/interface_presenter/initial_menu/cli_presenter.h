#ifndef CLI_PRESENTER
#define CLI_PRESENTER

#include <memory>

#include <console_viewer.h>

class CLIPresenter {
 public:
  CLIPresenter();

  enum MenuPoints { kQuit, kDemo, kRegistration, kLogin };

  void RunApplication();

 private:
  void RunSubMenu(int sub_menu);

  std::unique_ptr<ConsoleViewer> console_viewer_;
};

#endif  // CLI_PRESENTER
