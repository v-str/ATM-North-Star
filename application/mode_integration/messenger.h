#ifndef MESSENGER_H
#define MESSENGER_H

#include <string>

class Messenger {
 public:
  static void DisplayLauncherMessage();
  static void IncorrectInput();

 private:
  static void DisplayATMName();
  static void DisplayVersion();
  static void ModeSuggestion();

  static void DrawStrip(int length_of_strip);
  static void AddNewLine();

  static constexpr int greeting_strip_length_ = 40;
  static constexpr int version_strip_length_ = 20;
};

#endif  // MESSENGER_H
