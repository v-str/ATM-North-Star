#include "user.h"

#include <iostream>
#include <limits>

#include "system_utility.h"

using std::cin;
using std::cout;

static const int kMinimalSumForCredit = 1000;

AtmUser::AtmUser(const string &login, const string &password, double cash,
                 int credit, double monthly_payment,
                 int amount_of_credit_month) {
  account_info_.login_ = login;
  account_info_.password_ = password;
  account_info_.cash_ = cash;
  account_info_.credit_ = credit;
  account_info_.monthly_payment_ = monthly_payment;
  account_info_.amount_of_credit_month_ = amount_of_credit_month;
}

void AtmUser::Registration() {
  InitialRegistrationScreen();
  identification_of_user_.GetLogin();
  if (!identification_of_user_.IsNormalLogin()) {
    identification_of_user_.NoticeAboutIncorrectLogin();
  } else {
    identification_of_user_.GetPassword();
    if (!identification_of_user_.IsNormalPass()) {
      identification_of_user_.NoticeAboutIncorrectPassword();
    } else {
      identification_of_user_.NoticeAboutSuccessfulRegistration();
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
//  user_messanger_.ShowAccountInfo(identification_of_user_.account_info_);
    identification_of_user_.ShowAccountInformation();
    return user_input_.SuggestUserToExit();
}

bool AtmUser::Refill() {
  user_messanger_.ShowNotifyAboutCash();
  int money = 0;
  cin >> money;
  if (money >= 10 && money <= 50000) {
    account_info_.cash_ += money;
    user_messanger_.ShowUserBalance(account_info_.cash_);
  } else {
    user_messanger_.ShowIncorrectSum();
  }
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::CreditApplication() {
  if (AlreadyHasACredit()) {
    return RefuseToGrantAnotherCredit();
  } else {
    return ConsiderACredit();
  }
}

bool AtmUser::WithdrawCash() {
  int sum_of_withdrawal = SumOfWithdrawal();
  if (IsWithdrawalAcceptable(sum_of_withdrawal)) {
    user_messanger_.ShowSumOfWithdrawal(sum_of_withdrawal);
    string password = user_messanger_.GetPasswordFromUser();
    if (IsCorrectPassword(password)) {
      WithdrawFromAccount(sum_of_withdrawal);
      user_messanger_.ShowSuccessfulWithdrawal(sum_of_withdrawal,
                                               account_info_.cash_);
    } else {
      user_messanger_.ShowIncorrectPasswordMessage();
    }
  } else {
    user_messanger_.ShowUnacceptableWithdrawal(account_info_,
                                               sum_of_withdrawal);
  }
  return user_input_.SuggestUserToExit();
}

bool AtmUser::Statement() {
  utility_.ClearScreen();
  string spaces = GetSpaces(account_info_.cash_);
  int cash = account_info_.cash_;
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

bool AtmUser::AlreadyHasACredit() const { return account_info_.credit_ > 0; }

bool AtmUser::IsWithdrawalAcceptable(double cash_sum) const {
  return cash_sum > 0 && cash_sum <= account_info_.cash_;
}

void AtmUser::ShowIncorrectDataMessage() {
  user_messanger_.ShowIncorrectDataMessage();
}

void AtmUser::MonthToRepay() {
  cout << "\nThe number of months to repay the loan: ";
  GetCreditMonths();
}

bool AtmUser::ConsiderACredit() {
  user_messanger_.ShowNotifyAboutCredit();
  if (user_input_.GetChoiceFromUser() == 1) {
    return ConsiderACreditBasedOnCash();
  }
  return false;
}

bool AtmUser::ConsiderACreditBasedOnCash() {
  if (account_info_.cash_ >= kMinimalSumForCredit) {
    return GiveACredit();
  } else {
    return RefuseACredit();
  }
}

bool AtmUser::GiveACredit() {
  int maximal_sum_of_credit = 15 * account_info_.cash_;
  user_messanger_.ShowCreditConditions(maximal_sum_of_credit);
  int choice = user_input_.GetChoiceFromUser();
  if (choice == 1) {
    return MaxCreditCalculation(maximal_sum_of_credit);
  } else if (choice == 2) {
    return IndividualCreditCalculation(maximal_sum_of_credit);
  } else if (choice == 3) {
    return false;
  } else if (choice == 4) {
    return ExitCreditMenu();
  } else {
    return ReloadProgram();
  }
}

bool AtmUser::MaxCreditCalculation(int maximal_sum_of_credit) {
  MonthToRepay();

  utility_.ClearScreen();

  string user_login = account_info_.login_;
  user_messanger_.ShowInfoAboutCredit(user_login, maximal_sum_of_credit);

  int amount_of_months = account_info_.amount_of_credit_month_;

  double pay_per_month =
      user_credit_.CalculateCredit(maximal_sum_of_credit, amount_of_months);
  string menu_text = user_messanger_.SuggestToConfirmACredit();

  int choice = GetUserChoiceWithMenuText(menu_text, "\tEnter: ");
  if (choice == 1) {
    return EnrollACredit(maximal_sum_of_credit, pay_per_month);
  } else if (choice == 2) {
    return RepealACredit();
  } else if (choice == 3) {
    return ExitCreditMenu();
  } else {
    return ReloadProgram();
  }
}

bool AtmUser::EnrollACredit(double max_sum, double pay_per_month) {
  account_info_.credit_ = max_sum;
  account_info_.monthly_payment_ = pay_per_month;
  user_messanger_.ShowEnrollACredit();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::RepealACredit() {
  account_info_.amount_of_credit_month_ = 0;
  utility_.WriteTextWithDelay("\n\t# Credit is repealed...\n");
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool AtmUser::IndividualCreditCalculation(int maximal_sum_of_credit) {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("Individual calculating...\n\n");

  int user_sum_of_credit =
      user_credit_.GetIndividualSumOfCreditFromUser(maximal_sum_of_credit);
  MonthToRepay();

  int amount_of_months = account_info_.amount_of_credit_month_;

  user_messanger_.ShowIndividualCreditInfo(account_info_.login_,
                                           user_sum_of_credit);

  double pay_per_month =
      user_credit_.CalculateCredit(user_sum_of_credit, amount_of_months);

  string loan_confirmation_menu_text =
      user_messanger_.SuggestToConfirmACredit();

  int choice =
      GetUserChoiceWithMenuText(loan_confirmation_menu_text, "Enter: ");

  if (choice == 1) {
    return EnrollACredit(user_sum_of_credit, pay_per_month);
  } else if (choice == 2) {
    return false;
  } else if (choice == 3) {
    return ExitCreditMenu();
  } else {
    return ReloadProgram();
  }
}

bool AtmUser::ExitCreditMenu() {
  user_input_.ShowExitMessage();
  return true;
}

bool AtmUser::ReloadProgram() {
  ShowIncorrectDataMessage();
  return true;
}

int AtmUser::GetCreditMonths() {
  int months = 0;
  cin >> months;
  utility_.IgnoreCinLine();
  if (months <= 0 || months > 61) {
    return 0;
  } else {
    return account_info_.amount_of_credit_month_ = months;
  }
}

bool AtmUser::RefuseACredit() {
  int sum_of_cash = account_info_.cash_;
  user_messanger_.ShowRefuseACredit(sum_of_cash);

  return user_input_.SuggestUserToExit();
}

void AtmUser::SetupProgram() { utility_.ClearScreen(); }

bool AtmUser::RefuseToGrantAnotherCredit() {
  user_messanger_.RefusToGrantAnotherCredit();
  return ShowAccountInfo();
}

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
  return password == account_info_.password_;
}

void AtmUser::WithdrawFromAccount(int sum_of_withdrawal) {
  account_info_.cash_ -= sum_of_withdrawal;
}
