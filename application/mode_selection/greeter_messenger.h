#ifndef GREETER_MESSENGER_H
#define GREETER_MESSENGER_H

class GreeterMessenger {
 public:
  static void ShowGreetingMessage();

 private:
  static void DrawStrip(const char symbol, int length_of_strip);
};

#endif  // GREETER_MESSENGER_H
