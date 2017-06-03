#include "messenger.h"

#include <iostream>

void Messenger::DisplayLauncherMessage() {
  DisplayVersion();
  DisplayATMName();
  ModeSuggestion();
}

void Messenger::IncorrectInput() {
  std::cout << "# Incorrect input, please re-enter: ";
}

void Messenger::DisplayATMName() {
  AddNewLine();
  AddNewLine();
  DrawStrip(greeting_strip_length_);
  AddNewLine();
  std::cout << "#           ATM \"North star\"           #\n";
  DrawStrip(greeting_strip_length_);
  AddNewLine();
}

void Messenger::DisplayVersion() {
  DrawStrip(version_strip_length_);
  AddNewLine();
  std::cout << "#     v.1.0.1      #";
  AddNewLine();
  DrawStrip(version_strip_length_);
}

void Messenger::ModeSuggestion() {
  AddNewLine();
  DrawStrip(greeting_strip_length_);
  AddNewLine();
  std::cout << "#                                      #\n"
               "# Choose the interface:                #\n"
               "# 1.Console                            #\n"
               "# 2.Graphical                          #\n"
               "# ( press \'q\' for quit )               #\n"
               "#                                      #\n";
  DrawStrip(greeting_strip_length_);
  AddNewLine();
  AddNewLine();
  std::cout << "# Enter: ";
}

void Messenger::DrawStrip(int length_of_strip) {
  for (int i = 0; i < length_of_strip; ++i) {
    std::cout << "#";
  }
}

void Messenger::AddNewLine() { std::cout << "\n"; }
