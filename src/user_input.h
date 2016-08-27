#ifndef CORRECT_INPUT_H
#define CORRECT_INPUT_H

#include <string>

class UserInput {
  using string = std::string;

 public:
  UserInput() {}

  bool SuggestUserToExit() const;
  int GetValueFromUser() const;
  bool ShowIncorrectMessage() const;
  bool GetResultFromUser() const;

 private:
  int ConvertLineToChoice(const string &line) const;
  bool LineNotEmpty(const string &str) const;
  string GetLineFromUser() const;
  void ShowExitMessage() const;
};

#endif  // CORRECT_INPUT_H
