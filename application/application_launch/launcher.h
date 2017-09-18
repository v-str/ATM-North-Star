#ifndef LAUNCHER_H
#define LAUNCHER_H

class ConsoleInitialPresenter;
class GUIPresenter;

class Launcher {
 public:
  void LaunchConsoleMode();
  void LaunchGuiMode(int argc, char* argv[]);

  void DisplayErrorReport() const;

 private:
  ConsoleInitialPresenter* initial_menu_ = nullptr;
  GUIPresenter* gui_splash_creen_ = nullptr;

  // Programming by intentions
  // std::unique_ptr<BaseInterfacePresenter> interface_presenter_;
};

#endif  // LAUNCHER_H
