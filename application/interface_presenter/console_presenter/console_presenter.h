#ifndef CONSOLE_INTERFACE_PRESENTER_H
#define CONSOLE_INTERFACE_PRESENTER_H

#include <console_viewer.h>

class ConsolePresenter {
 public:
  enum MenuItem { kQuit, kDemo, kRegistration, kLogin };

  void RunApplication();

 private:
  ConsoleViewer console_viewer_;
};

#endif  // CONSOLE_INTERFACE_PRESENTER_H
