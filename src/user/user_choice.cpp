#include "user_choice.h"

const int kint_null = 0;

int UserChoice::GetUserChoiceWithMenuText(const string &menu_text,
                                          const string &choice_text) const {
  utility_.WriteTextWithDelay(menu_text);
  return GetUserChoice(choice_text);
}

int UserChoice::GetUserChoice(const string &choice_text) const {
  cout << choice_text;
  return GetChoiceFromUser();
}

int UserChoice::GetChoiceFromUser() const {
  int value = kint_null;
  while (!(cin >> value)) {
    cin.clear();
    while (cin.get() != '\n')
      ;
    user_messenger_.ShowIncorrectData();
  }
  return value;
}
