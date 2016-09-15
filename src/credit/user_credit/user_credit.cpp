#include "user_credit.h"

static const int kMinimalSumForCredit = 1000;

bool UserCredit::AlreadyHasACredit(UserIdentifier &user_identifier) const {
  return user_identifier.GetCredit() > 0;
}

void UserCredit::RefuseToGrantAnotherCredit() const {
  credit_messenger_.RefusToGrantAnotherCredit();
}

bool UserCredit::SuggestACredit(UserIdentifier &user_identifier) {
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

bool UserCredit::GiveACredit(UserIdentifier &user_identifier) {
  int maximal_sum_of_credit = 15 * user_identifier.GetCash();
  credit_messenger_.ShowCreditConditions(maximal_sum_of_credit);
  int choice = user_input_.GetChoiceFromUser();
  if (choice == 1) {
    return primary_credit_operations_.MaxCreditCalculation(
        user_identifier, maximal_sum_of_credit);
  } else if (choice == 2) {
    return primary_credit_operations_.IndividualCreditCalculation(
        user_identifier, maximal_sum_of_credit);
  } else if (choice == 3) {
    return false;
  } else if (choice == 4) {
    return credit_messenger_.ShowExitMessage();
  } else {
    return error_message.ShowIncorrectDataMessage();
  }
}

bool UserCredit::RefuseACredit(UserIdentifier &user_identifier) {
  credit_messenger_.ShowRefuseACredit(user_identifier.GetCash());

  return user_input_.SuggestUserToExit();
}
