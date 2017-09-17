#include <win_32_configurator.h>

#include <iostream>

int Win32Configurator::clear_screen_value_ = 0;

void Win32Configurator::ClearScreen() { clear_screen_value_ = system("cls"); }
