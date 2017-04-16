#include "cli_credit_department.h"

void CLICreditDepartment::StartCreditOperationFor(AtmUser* user) {
  int result_of_check = ResultOfUserCheck(*user);

  if (result_of_check == state_.kPositiveCheck) {
    SuggestCredit(user);
  } else if (result_of_check == state_.kCreditExist) {
    messenger_.RefuseACreditBasedOnAnotherCredit();
    messenger_.ShowIncorrectCashInformation(user->GetCash());
  } else if (result_of_check == state_.kInappropriateBalance) {
    messenger_.RefuseACreditBasedOnCash(user->GetCash());
  } else if (result_of_check == state_.kInvalidCheck) {
    messenger_.UnavailableCreditState();
  }
}

void CLICreditDepartment::SuggestCredit(AtmUser* user) {
  messenger_.NotifyAboutCredit();
  if (input_.GetValueFromUser() == kConsiderCredit) {
    ConsiderCredit(user);
  }
}

void CLICreditDepartment::ConsiderCredit(AtmUser* user) {
  int max_credit_sum = MaxCreditSum(user->GetCash());
  messenger_.ShowCreditConditions(max_credit_sum);
  int user_choice = input_.GetValueFromUser();
  if (user_choice == kMaxCreditSum) {
    SetCreditSum(max_credit_sum);
    SetCreditTerm(GetCreditTermFromUser());
  } else if (user_choice == kUserCreditSum) {
    SetCreditSum(GetCreditSumFromUser(max_credit_sum));
    SetCreditTerm(GetCreditTermFromUser());
  }
}

int CLICreditDepartment::GetCreditSumFromUser(int max_credit_sum) const {
  int user_credit_sum = 0;
  do {
    messenger_.ShowInfoAboutCreditSum();
    user_credit_sum = input_.GetValueFromUser();
  } while (user_credit_sum > max_credit_sum ||
           user_credit_sum == state_.kInvalidCheck || user_credit_sum < 0);

  return user_credit_sum;
}

int CLICreditDepartment::GetCreditTermFromUser() const {
  int months = 0;
  do {
    messenger_.ShowInfoAboutCreditMonth();
    months = input_.GetValueFromUser();
  } while (months < 0 || months > state_.kMaximalCreditTerm);
  return months;
}
