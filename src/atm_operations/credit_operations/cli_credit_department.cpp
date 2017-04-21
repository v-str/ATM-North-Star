#include "cli_credit_department.h"

void CLICreditDepartment::StartCreditOperationFor(AtmUser* user) {
  int result_of_check = ResultOfUserCheck(*user);

  if (result_of_check == CheckState::kPositiveCheck) {
    SuggestCredit(user);
  } else if (result_of_check == CheckState::kCreditExist) {
    messenger_.RefuseACreditBasedOnAnotherCredit();
    messenger_.ShowIncorrectCashInformation(user->GetCash());
  } else if (result_of_check == CheckState::kInappropriateBalance) {
    messenger_.RefuseACreditBasedOnCash(user->GetCash());
  } else if (result_of_check == CheckState::kInvalidCheck) {
    messenger_.UnavailableCreditState();
  }
}

void CLICreditDepartment::SuggestCredit(AtmUser* user) {
  messenger_.NotifyAboutCredit();
  if (input_.GetValueFromUser() == kConsiderCredit) {
    if (ConsiderCredit(user->GetCash())) {
      // ShowCreditPaymentStatement();
    }
  }
}

bool CLICreditDepartment::ConsiderCredit(int user_cash) {
  int max_credit_sum = MaxCreditSum(user_cash);
  int credit_sum = 0;
  messenger_.ShowCreditConditions(max_credit_sum);
  int user_choice = input_.GetValueFromUser();
  if (user_choice == kMaxCreditSum) {
    credit_sum = max_credit_sum;
  } else if (user_choice == kUserCreditSum) {
    credit_sum = GetCreditSumFromUser(max_credit_sum);
  } else if (user_choice == kExit || user_choice == CheckState::kInvalidCheck) {
    return false;
  } else {
    return false;
  }
  PerformCreditCalculations(credit_sum);
  return true;
}

void CLICreditDepartment::ShowCredit() {}

int CLICreditDepartment::GetCreditSumFromUser(int max_credit_sum) const {
  int user_credit_sum = 0;
  do {
    messenger_.ShowInfoAboutCreditSum();
    user_credit_sum = input_.GetValueFromUser();
  } while (!IsValid(user_credit_sum, max_credit_sum));

  return user_credit_sum;
}

int CLICreditDepartment::GetCreditTermFromUser() const {
  int months = 0;
  do {
    messenger_.ShowInfoAboutCreditMonth();
    months = input_.GetValueFromUser();
  } while (!IsValid(months));
  return months;
}

bool CLICreditDepartment::IsValid(int credit_sum, int max_credit_sum) const {
  return credit_sum < max_credit_sum &&
         credit_sum != CheckState::kInvalidCheck && credit_sum > 0;
}

bool CLICreditDepartment::IsValid(int months) const {
  return months > 0 && months < CheckState::kMaximalCreditTerm;
}

void CLICreditDepartment::PerformCreditCalculations(int credit_sum) {
  SetCreditSum(credit_sum);
  SetCreditTerm(GetCreditTermFromUser());
  CalculateCredit();
}
