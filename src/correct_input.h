#ifndef CORRECT_INPUT_H
#define CORRECT_INPUT_H

#include <string>

class CorrectInput {
  using string = std::string;

 public:
  CorrectInput() {}
  bool SuggestUserToExit() const;
  int GetValueFromUser() const;
  string GetLineFromUser() const;

 private:
  bool GetResultFromUser() const;
  int ConvertLineToChoice(const string &line) const;
  bool LineNotEmpty(const string &str) const;

  void ShowExitMessage() const;
};

#endif  // CORRECT_INPUT_H
