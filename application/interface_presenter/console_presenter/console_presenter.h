#ifndef CONSOLE_INTERFACE_PRESENTER_H
#define CONSOLE_INTERFACE_PRESENTER_H

#include <console_viewer.h>

#include <console_initial_menu.h>

class ConsolePresenter {
 public:
  enum MenuItem { kQuit, kDemo, kRegistration, kLogin };

  void RunApplication();

  void ProcessRegistrationData();

 private:
  ConsoleInitialMenu initial_menu_;

  ConsoleViewer console_viewer_;
};

#endif  // CONSOLE_INTERFACE_PRESENTER_H
