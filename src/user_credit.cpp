#include "user_credit.h"

static const int kMinimalSumForCredit = 1000;

UserCredit::UserCredit() {}

int UserCredit::GetIndividualSumOfCreditFromUser(int maximal_sum_of_credit) {
  int user_sum_of_credit = 0;
  do {
    utility_.WriteTextWithDelay(
        "The entered amount should not "
        "exceed the allowed credit.\n"
        "Enter the appropriate amount of credit: ");
    cout << "Enter: ";
    cin >> user_sum_of_credit;

    utility_.IgnoreCinLine();
  } while (user_sum_of_credit >= maximal_sum_of_credit);

  return user_sum_of_credit;
}

bool UserCredit::AlreadyHasACredit(AccountInfo &account_info) const {
  return account_info.credit_ > 0;
}

void UserCredit::RefuseToGrantAnotherCredit() const {
  credit_messenger_.RefusToGrantAnotherCredit();
}

bool UserCredit::ConsiderACredit(IdentificationOfUser &identification_of_user) {
  credit_messenger_.ShowNotifyAboutCredit();
  if (user_input_.GetChoiceFromUser() == 1) {
    return ConsiderACreditBasedOnCash(identification_of_user);
  }
  return false;
}

double UserCredit::CalculateCredit(int sum, int amount_of_months) {
  double x = (sum * 14) / 100;
  double pay_per_month = (sum / amount_of_months) + (x / 12);
  double all_payment = 0.0;
  for (int i = 0; i < amount_of_months; ++i) {
    cout << "\t* Payment month: " << i + 1 << "\tPayment sum: ";
    cout << pay_per_month << " $\n";
    utility_.Sleep(75);
    all_payment += pay_per_month;
  }
  cout << "\t\t\tTotal: " << all_payment << " $\n\n";
  return pay_per_month;
}

bool UserCredit::ConsiderACreditBasedOnCash(
    IdentificationOfUser &identification_of_user) {
  if (identification_of_user.account_info_.cash_ >= kMinimalSumForCredit) {
    return GiveACredit(identification_of_user);
  } else {
    return RefuseACredit(identification_of_user);
  }
}

bool UserCredit::GiveACredit(IdentificationOfUser &identification_of_user) {
  int maximal_sum_of_credit = 15 * identification_of_user.account_info_.cash_;
  credit_messenger_.ShowCreditConditions(maximal_sum_of_credit);
  int choice = user_input_.GetChoiceFromUser();
  if (choice == 1) {
    return MaxCreditCalculation(identification_of_user, maximal_sum_of_credit);
  } else if (choice == 2) {
    return IndividualCreditCalculation(identification_of_user,
                                       maximal_sum_of_credit);
  } else if (choice == 3) {
    return false;
  } else if (choice == 4) {
    return ExitCreditMenu();
  } else {
    return error_.ShowIncorrectDataMessage();
  }
}

bool UserCredit::MaxCreditCalculation(
    IdentificationOfUser &identification_of_user, int maximal_sum_of_credit) {
  MonthToRepay(identification_of_user);

  utility_.ClearScreen();

  string user_login = identification_of_user.account_info_.login_;
  credit_messenger_.ShowInfoAboutCredit(user_login, maximal_sum_of_credit);

  int amount_of_months =
      identification_of_user.account_info_.amount_of_credit_month_;

  double pay_per_month =
      CalculateCredit(maximal_sum_of_credit, amount_of_months);
  string menu_text = user_messanger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(menu_text, "\tEnter: ");
  if (choice == 1) {
    return EnrollACredit(identification_of_user, maximal_sum_of_credit,
                         pay_per_month);
  } else if (choice == 2) {
    return RepealACredit(identification_of_user);
  } else if (choice == 3) {
    return ExitCreditMenu();
  } else {
    return error_.ShowIncorrectDataMessage();
  }
}

bool UserCredit::IndividualCreditCalculation(
    IdentificationOfUser &identification_of_user, int maximal_sum_of_credit) {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("Individual calculating...\n\n");

  int user_sum_of_credit =
      GetIndividualSumOfCreditFromUser(maximal_sum_of_credit);
  MonthToRepay(identification_of_user);

  int amount_of_months =
      identification_of_user.account_info_.amount_of_credit_month_;

  user_messanger_.ShowIndividualCreditInfo(
      identification_of_user.account_info_.login_, user_sum_of_credit);

  double pay_per_month = CalculateCredit(user_sum_of_credit, amount_of_months);

  string loan_confirmation_menu_text =
      user_messanger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(
      loan_confirmation_menu_text, "Enter: ");

  if (choice == 1) {
    return EnrollACredit(identification_of_user, user_sum_of_credit,
                         pay_per_month);
  } else if (choice == 2) {
    return false;
  } else if (choice == 3) {
    return ExitCreditMenu();
  } else {
    return error_.ShowIncorrectDataMessage();
  }
}

bool UserCredit::EnrollACredit(IdentificationOfUser &identification_of_user,
                               double sum_of_credit, double pay_per_month) {
  identification_of_user.account_info_.credit_ = sum_of_credit;
  identification_of_user.account_info_.monthly_payment_ = pay_per_month;
  user_messanger_.ShowEnrollACredit();
  return user_input_.SuggestUserToExit();
}

bool UserCredit::RepealACredit(IdentificationOfUser &identification_of_user) {
  identification_of_user.account_info_.amount_of_credit_month_ = 0;
  utility_.WriteTextWithDelay("\n\t# Credit is repealed...\n");
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool UserCredit::RefuseACredit(IdentificationOfUser &identification_of_user) {
  int sum_of_cash = identification_of_user.account_info_.cash_;
  user_messanger_.ShowRefuseACredit(sum_of_cash);

  return user_input_.SuggestUserToExit();
}

bool UserCredit::ExitCreditMenu() {
  user_input_.ShowExitMessage();
  return true;
}

void UserCredit::MonthToRepay(IdentificationOfUser &identification_of_user) {
  cout << "\nThe number of months to repay the loan: ";
  GetCreditMonths(identification_of_user);
}

int UserCredit::GetCreditMonths(IdentificationOfUser &identification_of_user) {
  int months = 0;
  cin >> months;
  utility_.IgnoreCinLine();
  if (months <= 0 || months > 61) {
    return 0;
  } else {
    return identification_of_user.account_info_.amount_of_credit_month_ =
               months;
  }
}
