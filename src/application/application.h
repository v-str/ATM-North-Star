#ifndef CONSOLE_APPLICATION_H
#define CONSOLE_APPLICATION_H

#include "program_launcher.h"

class Application {
 public:
  enum ProgramMode { kConsoleMode = 1, kGraphicalMode };

  void RunProgram(ProgramMode mode);

 private:
  ProgramLauncher launcher_;
};

#endif  // CONSOLE_APPLICATION_H
