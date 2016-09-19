#ifndef USERCHOICE_H
#define USERCHOICE_H

#include <iostream>
#include <string>

#include "system_utility.h"
#include "user_input.h"
#include "user_messenger.h"

using std::cout;
using std::cin;

class UserChoice {
  using string = std::string;

 public:
  UserChoice();

  int GetUserChoiceWithMenuText(const string &menu_text,
                                const string &choice_text) const;

  int GetUserChoice(const string &choice_text) const;

  int GetChoiceFromUser() const;

 private:
  SystemUtility utility_;
  UserMessenger user_messenger_;
  UserInput user_input_;
};

#endif  // USERCHOICE_H
