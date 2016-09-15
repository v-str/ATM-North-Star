#include "user.h"

#include <iostream>
#include <limits>

#include "system_utility.h"

using std::cin;
using std::cout;

AtmUser::AtmUser(const string &login, const string &password, double cash,
                 int credit, double monthly_payment,
                 int amount_of_credit_month) {
  user_identifier_.InitLogin(login);
  user_identifier_.InitPassword(password);
  user_identifier_.InitCash(cash);
  user_identifier_.InitCredit(credit);
  user_identifier_.InitMonthlyPayment(monthly_payment);
  user_identifier_.InitAmountOfCreditMonth(amount_of_credit_month);
}

void AtmUser::Registration() {
  InitialRegistrationScreen();
  user_identifier_.GetLogin();
  if (!user_identifier_.IsNormalLogin()) {
    user_identifier_.NoticeAboutIncorrectLogin();
  } else {
    user_identifier_.GetPassword();
    if (!user_identifier_.IsNormalPass()) {
      user_identifier_.NoticeAboutIncorrectPassword();
    } else {
      user_identifier_.NoticeAboutSuccessfulRegistration();
      RunProgramUntilUserWantToExit();
    }
  }
}

void AtmUser::RunProgramUntilUserWantToExit() {
  SetupProgram();
  for (;;) {
    if (RunProgram()) break;
  }
}

bool AtmUser::RunProgram() {
  user_messanger_.ShowTransactionMenu();
  return HandleUserChoice(user_input_.GetChoiceFromUser());
}

bool AtmUser::HandleUserChoice(int choice) {
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

bool AtmUser::ShowAccountInfo() {
  user_identifier_.ShowAccountInformation();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::Refill() {
  user_messanger_.ShowNotifyAboutCash();
  int money = 0;
  cin >> money;
  if (money >= 10 && money <= 50000) {
    user_identifier_.AddCash(money);
    user_messanger_.ShowUserBalance(user_identifier_.ReturnCash());
  } else {
    error_.NoticeAboutIncorrectSum();
  }
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::CreditApplication() {
  if (user_credit_.AlreadyHasACredit(user_identifier_)) {
    user_credit_.RefuseToGrantAnotherCredit();
    user_identifier_.ShowAccountInformation();
    return user_input_.SuggestUserToExit();
  } else {
    return user_credit_.SuggestACredit(user_identifier_);
  }
}

bool AtmUser::WithdrawCash() {
  int sum_of_withdrawal = SumOfWithdrawal();
  if (IsWithdrawalAcceptable(sum_of_withdrawal)) {
    user_messanger_.ShowSumOfWithdrawal(sum_of_withdrawal);
    string password = user_identifier_.GetPasswordFromUser();
    if (IsCorrectPassword(password)) {
      WithdrawFromAccount(sum_of_withdrawal);
      user_messanger_.ShowSuccessfulWithdrawal(sum_of_withdrawal,
                                               user_identifier_.ReturnCash());
    } else {
      user_messanger_.ShowIncorrectPasswordMessage();
    }
  } else {
    int amount_of_cash = user_identifier_.ReturnCash();
    error_.ShowUnacceptableWithdrawal(amount_of_cash, sum_of_withdrawal);
  }
  return user_input_.SuggestUserToExit();
}

bool AtmUser::Statement() {
  utility_.ClearScreen();
  string spaces = GetSpaces(user_identifier_.ReturnCash());
  int cash = user_identifier_.ReturnCash();
  user_messanger_.ShowStatement(cash, spaces);
  return user_input_.SuggestUserToExit();
}

std::string AtmUser::GetSpaces(int cash) const {
  const int kSizeOfField = 12;
  const char space = ' ';
  return string(kSizeOfField - NumberOfDigits(cash), space);
}

int AtmUser::NumberOfDigits(int value) const {
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

bool AtmUser::IsWithdrawalAcceptable(double cash_sum) const {
  return cash_sum > 0 && cash_sum <= user_identifier_.ReturnCash();
}

void AtmUser::ShowIncorrectDataMessage() {
  user_messanger_.ShowIncorrectDataMessage();
}

void AtmUser::SetupProgram() { utility_.ClearScreen(); }

bool AtmUser::SuggestUserToExitWithConfirmationMenu() {
  user_messanger_.SuggestUserToExit();
  return user_input_.GetResultFromUserAboutExit();
}

void AtmUser::WishGoodDay() { user_messanger_.WishAGoodDay(); }

void AtmUser::ShowTransactionMenu() { user_messanger_.ShowTransactionMenu(); }

int AtmUser::GetUserChoiceWithMenuText(const string &menu_text,
                                       const string &choice_text) const {
  utility_.WriteTextWithDelay(menu_text);
  return GetUserChoice(choice_text);
}

int AtmUser::GetUserChoice(const string &choice_text) const {
  cout << choice_text;
  return GetChoiceFromUser();
}

int AtmUser::GetChoiceFromUser() const {
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

void AtmUser::WriteTextWithDelay(const string &text) const {
  for (const auto &symbol : text) {
    cout << symbol;
    cout.flush();
    utility_.Sleep(5);
  }
  cout << "\n";
}

void AtmUser::InitialRegistrationScreen() {
  user_messanger_.ShowRegistrationScreen();
}

int AtmUser::SumOfWithdrawal() const {
  cout << "\n\t# Please, enter the required sum: ";

  double credit_sum = 0.0;
  cin >> credit_sum;

  return credit_sum;
}

bool AtmUser::IsCorrectPassword(const string &password) {
  return password == user_identifier_.ReturnPassword();
}

void AtmUser::WithdrawFromAccount(int sum_of_withdrawal) {
  user_identifier_.DeductCash(sum_of_withdrawal);
}
