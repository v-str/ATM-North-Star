#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <memory>

#include <console_presenter.h>
#include <gui_presenter.h>

class Launcher {
 public:
  void LaunchConsoleMode();
  void LaunchGuiMode(int argc, char* argv[]);

  void DisplayErrorReport() const;

 private:
  std::unique_ptr<ConsolePresenter> initial_menu_;
  std::unique_ptr<GUIPresenter> gui_splash_creen_;

  // Programming by intentions
  // std::unique_ptr<BaseInterfacePresenter> interface_presenter_;
};

#endif  // LAUNCHER_H
