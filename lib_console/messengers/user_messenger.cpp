﻿#include "user_messenger.h"

void UserMessenger::ShowMainMenu() {
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.ClearScreen();
  console_editor_.WriteText(
      "\n\t################ Transaction menu ##################\n"
      "\t#                                                  #\n"
      "\t# 1. Account information            2. Refill      #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 3. Credit application             4. Withdrawal  #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 5. Statement                      6. Exit        #\n"
      "\t#                                                  #\n"
      "\t####################################################\n"
      "\tEnter: ");
}

void UserMessenger::ReRequestAboutExit() const {
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t# Do you really want to exit?");
}

void UserMessenger::WishAGoodDay() const {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.WriteText(
      "\n\t####################\n"
      "\t#                  #\n"
      "\t# Have a nice day! #\n"
      "\t#                  #\n"
      "\t####################\n\n");
}

void UserMessenger::ShowMainMenu() const {
  console_editor_.ClearScreen();
  console_editor_.WriteText(
      "\n\t################ Transaction menu ##################\n"
      "\t#                                                  #\n"
      "\t# 1. Account information            2. Refill      #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 3. Credit application             4. Withdrawal  #\n"
      "\t# ----------------------            ------------   #\n"
      "\t# 5. Statement                      6. Exit        #\n"
      "\t#                                                  #\n"
      "\t####################################################\n");
}

void UserMessenger::SuggestToExit() const {
  console_editor_.AddEmptyLineNTimes(1);
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t# 1. Exit to main page.\n"
      "\t# 2. Exit program.\n"
      "\t# Enter: ");
}

void UserMessenger::ShowIncorrectInput() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 10);
  console_editor_.WriteTextWithDelayPerSymbol("...", 100);
  console_editor_.WriteTextWithDelayPerSymbol("\n\t# Enter: ");
}

void UserMessenger::ShowIncorrectMainMenuInput() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t# Incorrect input, please try again", 20);
  console_editor_.Sleep(200);
}

void UserMessenger::ShowIncorrectRegisterData() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\tIncorrect input, "
      "\n\treload the program\n");
}