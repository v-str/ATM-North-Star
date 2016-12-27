#ifndef APPLICATION_H
#define APPLICATION_H

#include "console_application.h"

class Application {
 public:
  enum ProgramMode { kConsoleMode, kGraphicalMode };

  void RunProgramByMode(ProgramMode mode);

 private:
  ConsoleApplication console_app_;
};

#endif  // APPLICATION_H
