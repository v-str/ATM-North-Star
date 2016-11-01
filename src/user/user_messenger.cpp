#include "user_messenger.h"

#include <iostream>

void UserMessenger::ShowMainMenu() {
  utility_.ClearScreen();
  string select =
      "\n\t################ Transaction menu ##################\n"
      "\t#                                                  #\n"
      "\t# 1. Account information            2. Refill      #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 3. Credit application             4. Withdrawal  #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 5. Statement                      6. Exit        #\n"
      "\t#                                                  #\n"
      "\t####################################################\n";
  std::cout << select;
  std::cout << "\tEnter: ";
}

void UserMessenger::ShowNotifyAboutCash() {
  std::cout << "\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  std::cout << "\n\t";
  utility_.WriteTextWithDelay(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$");
  std::cout << "\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  std::cout << "\n";
  std::cout << "\t# Please enter the sum of money($): ";
}

void UserMessenger::ShowIncorrectDataMessage() {
  utility_.WriteTextWithDelay(
      "\t Data is not correct, please reload the program.\n\n");
  std::cin.get();
}

void UserMessenger::ShowIncorrectMonthInput() {
  std::cout << "Number of credit month can't be more than 60\n";
  std::cout << "The number of months to repay the loan: ";
}

void UserMessenger::SuggestUserToExit() const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "\n\t# Do you really want to exit?\n"
      "\t# 1. No, go to main\n"
      "\t# 2. Yes, exit\n");
  std::cout << "\t# Enter: ";
}

void UserMessenger::WishAGoodDay() const {
  std::cout << "\n\t####################\n"
               "\t#                  #\n"
               "\t# Have a nice day! #\n"
               "\t#                  #\n"
               "\t####################\n\n";
}

void UserMessenger::ShowMainMenu() const {
  utility_.ClearScreen();
  string select =
      "\n\t################ Transaction menu ##################\n"
      "\t#                                                  #\n"
      "\t# 1. Account information            2. Refill      #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 3. Credit application             4. Withdrawal  #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 5. Statement                      6. Exit        #\n"
      "\t#                                                  #\n"
      "\t####################################################\n";
  std::cout << select;
}

void UserMessenger::ShowSuggestionAboutExit() const {
  utility_.WriteTextWithDelay(
      "\n\t# 1. Exit to main page.\n"
      "\t# 2. Exit program.\n");
  std::cout << "\t# Enter: ";
}

void UserMessenger::ShowIncorrectSumInput() const {
  std::cout << "\t# Incorrect input, please try again:\n"
               "\t# Enter: ";
}

void UserMessenger::ShowIncorrectData() const {
  std::cout << "\n\tIncorrect data. Please, repeat.\n";
  std::cout << "\t-------------------------------\n";
  std::cout << "\tSelect: ";
}

void UserMessenger::ShowIncorrectRegisterData() const {
  utility_.WriteTextWithDelay(
      "\n\tIncorrect input, "
      "\n\treload the program\n");
}
