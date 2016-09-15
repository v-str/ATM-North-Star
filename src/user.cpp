#include "user.h"

#include <iostream>
#include <limits>

#include "system_utility.h"

using std::cin;
using std::cout;

AtmUser::AtmUser(const string &login, const string &password, double cash,
                 int credit, double monthly_payment,
                 int amount_of_credit_month) {
  user_identifier_.ShowLogin(login);
  user_identifier_.ShowPassword(password);
  cash_operator_.SetCash(cash);
  cash_operator_.SetCredit(credit);
  cash_operator_.SetMonthlyPayment(monthly_payment);
  cash_operator_.SetAmountOfCreditMonth(amount_of_credit_month);
}

void AtmUser::Registration() {
  InitialRegistrationScreen();
  user_identifier_.ShowLogin();
  if (!user_identifier_.IsNormalLogin()) {
    error_message_.NoticeAboutIncorrectLoginMessage();
  } else {
    user_identifier_.ShowPassword();
    if (!user_identifier_.IsNormalPass()) {
      error_message_.NoticeAboutIncorrectFormatPasswordMessage();
    } else {
      successful_action_.NoticeAboutSuccessfulRegistration(cash_operator_);
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
  ShowAccountInformation();
  return user_input_.SuggestUserToExit();
}

void AtmUser::ShowAccountInformation() {
  cout << "\t";
  user_messanger_.WriteSymbolsNTimes('-', 45);

  user_messanger_.WriteUserInfo("Login", user_identifier_.GetLogin());
  user_messanger_.WriteUserInfo("Password", user_identifier_.GetPassword());
  user_messanger_.WriteUserInfo("Balance",
                                std::to_string(cash_operator_.GetCash()));
  user_messanger_.WriteUserInfo("Credit",
                                std::to_string(cash_operator_.GetCredit()));
  user_messanger_.WriteUserInfo(
      "Monthly payment $", std::to_string(cash_operator_.GetMonthlyPayment()));
  user_messanger_.WriteUserInfo(
      "Credit term", std::to_string(cash_operator_.GetAmountOfCreditMonth()));
}

bool AtmUser::Refill() {
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

bool AtmUser::CreditApplication() {
  if (user_credit_.AlreadyHasACredit(cash_operator_)) {
    user_credit_.RefuseToGrantAnotherCredit();
    ShowAccountInformation();
    return user_input_.SuggestUserToExit();
  } else {
    string user_login = user_identifier_.GetLogin();
    return user_credit_.SuggestACredit(cash_operator_, user_login);
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

bool AtmUser::Statement() {
  utility_.ClearScreen();
  string spaces = GetSpaces(cash_operator_.GetCash());
  int cash = cash_operator_.GetCash();
  user_messanger_.ShowStatement(cash, spaces);
  return user_input_.SuggestUserToExit();
}

std::string AtmUser::GetSpaces(int convertation_cash_to_space) const {
  const int kSizeOfCheckField = 12;
  const char space = ' ';
  return string(kSizeOfCheckField - NumberOfDigits(convertation_cash_to_space),
                space);
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
  return cash_sum > 0 && cash_sum <= cash_operator_.GetCash();
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
  return password == user_identifier_.GetPassword();
}

void AtmUser::WithdrawFromAccount(int sum_of_withdrawal) {
  cash_operator_.WithdrawCashFromUser(sum_of_withdrawal);
}
