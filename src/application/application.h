#ifndef APPLICATION_H
#define APPLICATION_H

#include "console_mode.h"

class Application {
 public:
  enum ProgramMode { kConsoleMode = 1, kGraphicalMode };

  void RunProgram(int mode);

 private:
  ConsoleMode console_mode_;
};

#endif  // APPLICATION_H
