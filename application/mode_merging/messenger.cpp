#include "messenger.h"

#include <iostream>

void Messenger::DisplayLauncherMessage() {
  DisplayVersion();

  std::cout << "\n\nATM system \"North Star\"\n\n\n"
               "Choose the interface:\n\n"
               "1.Console \n"
               "2.Graphical \n\n"
               "(\'q\' for quit)\n\n"
               "Enter: ";
}

void Messenger::IncorrectInput() {
  std::cout << "Incorrect input, please re-enter: ";
}

void Messenger::DisplayVersion() {
  DrawStrip(version_strip_length_);
  std::cout << "\n-     v.1.0.1      -\n";
  DrawStrip(version_strip_length_);
}

void Messenger::DrawStrip(int length_of_strip) {
  for (int i = 0; i < length_of_strip; ++i) {
    std::cout << "-";
  }
}
