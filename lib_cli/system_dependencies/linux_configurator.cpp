#include <linux_configurator.h>

#include <iostream>

int LinuxConfigurator::clear_screen_value_ = 0;

void LinuxConfigurator::ClearScreen() { clear_screen_value_ = system("clear"); }
