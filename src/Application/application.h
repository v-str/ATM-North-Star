#ifndef APPLICATION_H
#define APPLICATION_H

#include "main_menu.h"

class Application {
 public:
  enum ProgramMode { kConsoleMode, kGraphicalMode };

  void RunProgramByMode(ProgramMode mode);

 private:
  MainMenu main_menu_;
};

#endif  // APPLICATION_H
