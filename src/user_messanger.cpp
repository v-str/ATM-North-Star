#include "user_messanger.h"

static const int kMaxLenghtOfLogin = 21;

UserMessanger::UserMessanger() {}

void UserMessanger::WriteSymbolsNTimes(char symbol, int n) const {
  for (int i = 0; i < n; ++i) {
    cout << symbol;
  }
}

void UserMessanger::ShowRegistrationScreen() {
  utility_.ClearScreen();

  cout << "\n\t\t   ********************\n"
          "\t\t   *   REGISTRATION   *\n"
          "\t\t   ********************\n";

  cout << "\n\n\n\t\tLogin: ";

  WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
}

void UserMessanger::ShowIncorrectLoginMessage() {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay(
      "\t\t|Incorrect login.           |\n"
      "\t\t|It must be more than 1 and |\n"
      "\t\t|less than 20 symbols.      |\n"
      "\t\t|Please, reload the program.|");
  cout << "\t\t|---------------------------|\n\n";
}

void UserMessanger::ShowIncorrectPasswordMessage() {
  utility_.ClearScreen();
  cout << "\n\n\n\n\t\t\t|---------------------------|\n";
  utility_.WriteTextWithDelay(
      "\t\t|Incorrect password.        |\n"
      "\t\t|It must be in XXXX format. |\n"
      "\t\t|Please, reload the program.|");
  cout << "\t\t|---------------------------|\n\n\t\t\t";
}

void UserMessanger::ShowTransactionMenu() {
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
  cout << select;
  cout << "\tSelect: ";
}

void UserMessanger::WriteUserInfo(const UserMessanger::string &info_title,
                                  const UserMessanger::string &value) {
  cout << "\n\t# " << info_title << ": " << value << "\n\t";
  WriteSymbolsNTimes('-', 30);
  utility_.Sleep(100);
}
