#include <console_login_menu.h>

#include <iostream>

#include <linux_configurator.h>

ConsoleLoginMenu::ConsoleLoginMenu() {}

void ConsoleLoginMenu::RunLoginMenu() {
  LinuxConfigurator::ClearScreen();
  std::cout << "Login menu is under construction\n";
}
