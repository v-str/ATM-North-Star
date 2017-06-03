#ifndef MESSENGER_H
#define MESSENGER_H

#include <string>

class Messenger {
 public:
  static void DisplayLauncherMessage();
  static void IncorrectInput();

 private:
  static void DisplayVersion();

  static void DrawStrip(int length_of_strip);

  static constexpr int version_strip_length_ = 20;
};

#endif  // MESSENGER_H
