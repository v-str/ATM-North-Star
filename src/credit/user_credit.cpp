#include "user_credit.h"

static const int kMinimalSumForCredit = 1000;

UserCredit::UserCredit() {}

bool UserCredit::AlreadyHasACredit(UserIdentifier &user_identifier) const {
  return user_identifier.ReturnCredit() > 0;
}

bool UserCredit::ConsiderACredit(UserIdentifier &user_identifier) {
  credit_messenger_.ShowNotifyAboutCredit();
  if (user_input_.GetChoiceFromUser() == 1) {
    return ConsiderACreditBasedOnCash(user_identifier);
  }
  return false;
}

bool UserCredit::ConsiderACreditBasedOnCash(UserIdentifier &user_identifier) {
  if (user_identifier.IsCreditAvailable()) {
    return GiveACredit(user_identifier);
  } else {
    return RefuseACredit(user_identifier);
  }
}
//============================================================================
bool UserCredit::GiveACredit(UserIdentifier &user_identifier) {
  int maximal_sum_of_credit = 15 * user_identifier.ReturnCash();
  credit_messenger_.ShowCreditConditions(maximal_sum_of_credit);
  int choice = user_input_.GetChoiceFromUser();
  if (choice == 1) {
    return primary_credit_operations_.MaxCreditCalculation(
        user_identifier, maximal_sum_of_credit);
  } else if (choice == 2) {
    return IndividualCreditCalculation(user_identifier, maximal_sum_of_credit);
  } else if (choice == 3) {
    return false;
  } else if (choice == 4) {
    return credit_messenger_.ShowExitMessage();
  } else {
    return error_.ShowIncorrectDataMessage();
  }
}

void UserCredit::RefuseToGrantAnotherCredit() const {
  credit_messenger_.RefusToGrantAnotherCredit();
}

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
  } while (user_sum_of_credit > maximal_sum_of_credit);

  return user_sum_of_credit;
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

//bool UserCredit::MaxCreditCalculation(UserIdentifier &user_identifier,
//                                      int maximal_sum_of_credit) {
//  int amount_of_credit_months =
//      secondary_credit_operation_.GetAmountOfCreditMonthsFromUser();

//  utility_.ClearScreen();

//  string user_login = user_identifier.ReturnLogin();

//  credit_messenger_.ShowInfoAboutCredit(user_login, maximal_sum_of_credit);

//  double pay_per_month = primary_credit_operations_.CalculateCredit(
//      maximal_sum_of_credit, amount_of_credit_months);

//  string menu_text = credit_messenger_.SuggestToConfirmACredit();

//  int choice = user_choice_.GetUserChoiceWithMenuText(menu_text, "\tEnter: ");

//  if (choice == 1) {
//    return secondary_credit_operation_.EnrollACredit(
//        user_identifier, maximal_sum_of_credit, pay_per_month);
//  } else if (choice == 2) {
//    return secondary_credit_operation_.RepealACredit(user_identifier);
//  } else if (choice == 3) {
//    return credit_messenger_.ShowExitMessage();
//  } else {
//    return error_.ShowIncorrectDataMessage();
//  }
//}

bool UserCredit::IndividualCreditCalculation(UserIdentifier &user_identifier,
                                             int maximal_sum_of_credit) {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("Individual calculating...\n\n");

  int user_sum_of_credit =
      GetIndividualSumOfCreditFromUser(maximal_sum_of_credit);

  int amount_of_credit_months = GetAmountOfMonthToRepayACredit();

  credit_messenger_.ShowIndividualCreditInfo(user_identifier.ReturnLogin(),
                                             user_sum_of_credit);

  double pay_per_month =
      CalculateCredit(user_sum_of_credit, amount_of_credit_months);

  string loan_confirmation_menu_text =
      credit_messenger_.SuggestToConfirmACredit();

  int choice = user_choice_.GetUserChoiceWithMenuText(
      loan_confirmation_menu_text, "Enter: ");

  if (choice == 1) {
    user_identifier.AssignACredit(user_sum_of_credit);
    user_identifier.AssignAMonthlyPayment(pay_per_month);
    return EnrollACredit();
  } else if (choice == 2) {
    return false;
  } else if (choice == 3) {
    return credit_messenger_.ShowExitMessage();
  } else {
    return error_.ShowIncorrectDataMessage();
  }
}

bool UserCredit::EnrollACredit() const {
  credit_messenger_.ShowEnrollACredit();
  return user_input_.SuggestUserToExit();
}

bool UserCredit::RepealACredit() const {
  utility_.WriteTextWithDelay("\n\t# Credit is repealed...\n");
  utility_.IgnoreCinLine();
  return user_input_.SuggestUserToExit();
}

bool UserCredit::RefuseACredit(UserIdentifier &user_identifier) {
  credit_messenger_.ShowRefuseACredit(user_identifier.ReturnCash());

  return user_input_.SuggestUserToExit();
}

int UserCredit::GetAmountOfMonthToRepayACredit() {
  cout << "\nThe number of months to repay the loan: ";
  return GetCreditMonths();
}

int UserCredit::GetCreditMonths() {
  int months = 0;
  cin >> months;
  utility_.IgnoreCinLine();
  return months;
}
