#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include "application.h"

class ModeSelector {
 public:
  ModeSelector();

  enum ProgramMode { kConsoleMode = 1, kGraphicalMode };

  void RunProgramByMode(ProgramMode mode);

 private:
  std::unique_ptr<Application> app_;
};

#endif  // APPLICATION_H
