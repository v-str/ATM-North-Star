#ifndef APPLICATION_H
#define APPLICATION_H

#include "console_launcher.h"

class Application {
 public:
  enum ProgramMode { kConsoleMode = 1, kGraphicalMode };

  void RunProgram(int mode);

 private:
  ConsoleLauncher launcher_;
};

#endif  // APPLICATION_H
