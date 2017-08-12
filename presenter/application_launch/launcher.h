#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <memory>

class Launcher {
 public:
  void LaunchConsoleMode();
  void LaunchGuiMode(int argc, char* argv[]);

  void DisplayErrorReport() const;

 private:
  //  std::unique_ptr<cli::InitialMenu> initial_menu_;
  //  std::unique_ptr<gui::GraphicalSplashScreen> gui_splash_creen_;
};

#endif  // LAUNCHER_H
