#ifndef GREETING_MESSENGER_H
#define GREETING_MESSENGER_H

class GreetingMessenger {
 public:
  static void ShowGreetingMessage();

 private:
  static void DrawStrip(const char strip_symbol, int strip_length);

  static constexpr int strip_length_ = 50;
};

#endif  // GREETING_MESSENGER_H
