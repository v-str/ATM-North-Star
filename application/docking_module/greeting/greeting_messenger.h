#ifndef GREETING_MESSENGER_H
#define GREETING_MESSENGER_H

#include <string>

class GreetingMessenger {
 public:
  static void ShowGreetingMessage();

 private:
  static void DrawStrip(const char strip_symbol, int strip_length);
  static void AddString(const char strip_symbol, const std::string& string);

  static constexpr int strip_length_ = 50;
};

#endif  // GREETING_MESSENGER_H
