#ifndef LAUNCHER_H
#define LAUNCHER_H

class ConsoleInitialPresenter;
class GraphicalInitialPresenter;

class Launcher {
 public:
  void LaunchConsoleMode();
  void LaunchGuiMode(int argc, char* argv[]);

  void DisplayErrorReport() const;

 private:
  ConsoleInitialPresenter* console_initial_presenter_ = nullptr;
  GraphicalInitialPresenter* gui_splash_creen_ = nullptr;
};

#endif  // LAUNCHER_H
