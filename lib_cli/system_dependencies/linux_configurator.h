#ifndef LINUX_H
#define LINUX_H

#include <string>

class LinuxConfigurator {
 public:
  static void ClearScreen();

 private:
  static int clear_screen_value_;
};

#endif  // LINUX_H
