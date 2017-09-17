#ifndef WIN_32_H
#define WIN_32_H

#include <string>

class Win32Configurator {
 public:
  static void ClearScreen();

 private:
  static int clear_screen_value_;
};

#endif  // WIN_32_H
