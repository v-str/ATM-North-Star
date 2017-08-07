#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <memory>

#include <graphical_splash_screen.h>
#include <initial_menu.h>

class Launcher {
 public:
  void LaunchConsoleMode();
  void LaunchGuiMode(int argc, char* argv[]);

 private:
  std::unique_ptr<cli::InitialMenu> initial_menu_;
  std::unique_ptr<gui::GraphicalSplashScreen> gui_splash_creen_;
};

#endif  // LAUNCHER_H
