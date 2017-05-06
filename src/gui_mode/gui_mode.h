#ifndef GUI_MODE_H
#define GUI_MODE_H

class AtmSplashScreen;

class GuiMode {
 public:
  GuiMode();
  ~GuiMode();

  void RunSplashScreen();

 private:
  AtmSplashScreen* splash_screen_ = nullptr;
};

#endif  // GUI_MODE_H
