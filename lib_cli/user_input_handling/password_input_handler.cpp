#include <password_input_handler.h>

#ifdef WIN32
#include <windows.h>
#else
#include <termios.h>  // general terminal interface
#include <unistd.h>   // symbolic constants
#endif

#include <iostream>

std::string PasswordInputHandler::kPasswordString = "";

std::string PasswordInputHandler::GetPassword() {
  SetEcho(false);

  std::getline(std::cin, kPasswordString);

  SetEcho(true);

  return kPasswordString;
}

void PasswordInputHandler::SetEcho(bool enable) {
#ifdef WIN32
  HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
  DWORD mode;
  GetConsoleMode(hStdin, &mode);

  if (!enable) {
    mode &= ~ENABLE_ECHO_INPUT;
  } else {
    mode |= ENABLE_ECHO_INPUT;
  }

  SetConsoleMode(hStdin, mode);

#else
  struct termios terminal_interface;
  tcgetattr(STDIN_FILENO, &terminal_interface);

  if (!enable) {
    terminal_interface.c_lflag &= ~ECHO;
  } else {
    terminal_interface.c_lflag |= ECHO;
  }

  (void)tcsetattr(STDIN_FILENO, TCSANOW, &terminal_interface);

#endif
}
