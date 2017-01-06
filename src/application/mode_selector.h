#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include "console_application.h"

class ModeSelector {
 public:
  enum ProgramMode { kConsoleMode, kGraphicalMode };

  void RunProgramByMode(ProgramMode mode);

 private:
  std::unique_ptr<ConsoleApplication> console_app_;
};

#endif  // APPLICATION_H
