#ifndef INITIAL_INPUT_H
#define INITIAL_INPUT_H

class InitialInput {
 public:
  static int GetValueFromUser();

 private:
  static constexpr int kConsoleMode = 1;
  static constexpr int kGuiMode = 2;
  static constexpr int kExit = 0;
  static constexpr int kInvalidChoice = -1;
};

#endif  // INITIAL_INPUT_H
