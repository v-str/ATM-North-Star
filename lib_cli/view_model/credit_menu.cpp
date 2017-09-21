#include <credit_menu.h>

#include <credit_messenger.h>
#include <user_input_handler.h>

void CreditMenu::DisplayCreditMenu() {
  CreditMessenger::DisplayCreditMenu();
  ProcessUserInput();
}

bool CreditMenu::IsUserWantCredit() const { return user_want_credit_; }

bool CreditMenu::IsUserWantCreditCalculator() const {
  return user_want_credit_calculator_;
}

bool CreditMenu::IsUserWantMainMenu() const { return user_want_main_menu_; }

bool CreditMenu::IsUserWantQuit() const { return user_want_quit_; }

void CreditMenu::ProcessUserInput() {
  for (;;) {
    UserInputHandler user_input_handler;
    int user_input = user_input_handler.GetDigitInputFromUser();

    // if (contain menu item){
    //  break;
    // } else {
    // CreditMessenger::ShowIncorrectInput();
    // }
  }
}

void CreditMenu::ResetManipulationFlags() {
  user_want_credit_ = false;
  user_want_credit_calculator_ = false;
  user_want_main_menu_ = false;
  user_want_quit_ = false;
}
