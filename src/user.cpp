#include "user.h"

#include <iostream>
#include <limits>

#include "system_utility.h"

using std::cin;
using std::cout;

User::User(const string &login, const string &password, double cash, int credit,
           double monthly_payment, int amount_of_credit_month) {
  user_identifier_.SetLogin(login);
  user_identifier_.SetPassword(password);
  cash_operator_.SetCash(cash);
  cash_operator_.SetCredit(credit);
  cash_operator_.SetMonthlyPayment(monthly_payment);
  cash_operator_.SetAmountOfCreditMonth(amount_of_credit_month);
}

void User::Registration() {
  user_messanger_.ShowRegistrationScreen();
  user_messanger_.ShowInitialLoginText();
  user_identifier_.EnterInitialLogin();
  if (!user_identifier_.IsNormalLogin()) {
    error_message_.NoticeAboutIncorrectLoginMessage();
  } else {
    user_messanger_.ShowInitialPasswordText();
    user_identifier_.EnterinitialPassword();
    if (!user_identifier_.IsNormalPass()) {
      error_message_.NoticeAboutIncorrectFormatPasswordMessage();
    } else {
      successful_action_.NoticeAboutSuccessfulRegistration(cash_operator_);
      RunProgramUntilUserWantToExit();
    }
  }
}

void User::RunProgramUntilUserWantToExit() {
  SetupProgram();
  for (;;) {
    if (RunProgram()) break;
  }
}

bool User::RunProgram() {
  user_messanger_.ShowTransactionMenu();
  return HandleUserChoice(user_input_.GetChoiceFromUser());
}

bool User::HandleUserChoice(int choice) {
  utility_.ClearScreen();

  if (choice == kAccountSection) {
    return ShowAccountInfo();
  } else if (choice == kRefillSection) {
    return Refill();
  } else if (choice == kCreditSection) {
    return CreditApplication();
  } else if (choice == kWidthdrawalSection) {
    return WithdrawCash();
  } else if (choice == kStatementSection) {
    return Statement();
  } else if (choice == kExitSection) {
    return SuggestUserToExitWithConfirmationMenu();
  } else {
    return user_input_.ShowIncorrectMessage();
  }
}

bool User::ShowAccountInfo() {
  user_messanger_.ShowAccountInformation(user_identifier_, cash_operator_);
  return user_input_.SuggestUserToExit();
}

bool User::Refill() {
  user_messanger_.ShowNotifyAboutCash();
  int money = 0;
  cin >> money;
  if (money >= 10 && money <= 50000) {
    cash_operator_.AddCash(money);
    user_messanger_.ShowUserBalance(cash_operator_.GetCash());
  } else {
    error_message_.NoticeAboutIncorrectSum();
  }
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool User::CreditApplication() {
  if (user_credit_.AlreadyHasACredit(cash_operator_)) {
    user_credit_.RefuseToGrantAnotherCredit();
    user_messanger_.ShowAccountInformation(user_identifier_, cash_operator_);
    return user_input_.SuggestUserToExit();
  } else {
    string user_login = user_identifier_.GetLogin();
    return user_credit_.SuggestACredit(cash_operator_, user_login);
  }
}

bool User::WithdrawCash() {
  int sum_of_withdrawal = withdrawal_.SumOfWithdrawal();
  if (IsWithdrawalAcceptable(sum_of_withdrawal)) {
    user_messanger_.ShowSumOfWithdrawal(sum_of_withdrawal);
    string password = user_identifier_.GetPasswordFromUser();
    if (IsCorrectPassword(password)) {
      WithdrawFromAccount(sum_of_withdrawal);
      user_messanger_.ShowSuccessfulWithdrawal(sum_of_withdrawal,
                                               cash_operator_.GetCash());
    } else {
      user_messanger_.ShowIncorrectPasswordMessage();
    }
  } else {
    int amount_of_cash = cash_operator_.GetCash();
    error_message_.ShowUnacceptableWithdrawal(amount_of_cash,
                                              sum_of_withdrawal);
  }
  return user_input_.SuggestUserToExit();
}

bool User::Statement() {
  utility_.ClearScreen();
  string spaces = GetSpaces(cash_operator_.GetCash());
  int cash = cash_operator_.GetCash();
  user_messanger_.ShowStatement(cash, spaces);
  return user_input_.SuggestUserToExit();
}

std::string User::GetSpaces(int convertation_cash_to_space) const {
  const int kSizeOfCheckField = 12;
  const char space = ' ';
  return string(kSizeOfCheckField - NumberOfDigits(convertation_cash_to_space),
                space);
}

int User::NumberOfDigits(int value) const {
  int number_of_digits = 0;
  if (value == 0) {
    return number_of_digits = 1;
  } else {
    while (value != 0) {
      ++number_of_digits;
      value /= 10;
    }
  }
  return number_of_digits;
}

bool User::IsWithdrawalAcceptable(double cash_sum) const {
  return cash_sum > 0 && cash_sum <= cash_operator_.GetCash();
}

void User::ShowIncorrectDataMessage() {
  user_messanger_.ShowIncorrectDataMessage();
}

void User::SetupProgram() { utility_.ClearScreen(); }

bool User::SuggestUserToExitWithConfirmationMenu() {
  user_messanger_.SuggestUserToExit();
  return user_input_.GetResultFromUserAboutExit();
}

void User::WishGoodDay() { user_messanger_.WishAGoodDay(); }

void User::ShowTransactionMenu() { user_messanger_.ShowTransactionMenu(); }

int User::GetUserChoiceWithMenuText(const string &menu_text,
                                    const string &choice_text) const {
  utility_.WriteTextWithDelay(menu_text);
  return GetUserChoice(choice_text);
}

int User::GetUserChoice(const string &choice_text) const {
  cout << choice_text;
  return GetChoiceFromUser();
}

int User::GetChoiceFromUser() const {
  int value = 0;
  while (!(cin >> value)) {
    cin.clear();
    while (cin.get() != '\n')
      ;
    cout << "\tIncorrect data. Please, repeat.\n";
    cout << "\t-------------------------------\n";
    cout << "\tSelect: ";
  }
  return value;
}

void User::WriteTextWithDelay(const string &text) const {
  for (const auto &symbol : text) {
    cout << symbol;
    cout.flush();
    utility_.Sleep(5);
  }
  cout << "\n";
}

bool User::IsCorrectPassword(const string &password) {
  return password == user_identifier_.GetPassword();
}

void User::WithdrawFromAccount(int sum_of_withdrawal) {
  cash_operator_.WithdrawCashFromUser(sum_of_withdrawal);
}
