#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <memory>

#include <initial_menu.h>

class Launcher {
 public:
  Launcher();

  void LaunchConsoleMode();
  void LaunchGuiMode(int argc, char* argv[]);

 private:
  std::unique_ptr<cli::InitialMenu> initial_menu_;
};

#endif  // LAUNCHER_H
