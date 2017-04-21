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
  messenger_.ShowInfoAboutCreditSum();
  do {
    messenger_.SuggestEnterCreditSum();
    user_credit_sum = input_.GetValueFromUser();
  } while (!IsValid(user_credit_sum, max_credit_sum));

  return user_credit_sum;
}

int CLICreditDepartment::GetCreditTermFromUser() const {
  int months = 0;
  messenger_.ShowInfoAboutCreditTerm();
  do {
    messenger_.SuggestEnterCreditTerm();
    months = input_.GetValueFromUser();
  } while (!IsValid(months));
  return months;
}

bool CLICreditDepartment::IsValid(int credit_sum, int max_credit_sum) const {
  if (credit_sum > max_credit_sum) {
    messenger_.ShowError("Error! Exceeding of desired credit sum.");
    return false;
  } else if (credit_sum == CheckState::kInvalidCheck) {
    messenger_.ShowError("Error! Incorrect credit sum.");
    return false;
  } else if (credit_sum < CheckState::kMinimalCreditSum) {
    messenger_.ShowError("Error! Credit sum should be greater than $500.");
    return false;
  }
  return true;
}

bool CLICreditDepartment::IsValid(int months) const {
  if (months > CheckState::kMaximalCreditTerm) {
    messenger_.ShowError("Error! Exceeding of desired credit term.");
    return false;
  } else if (months == CheckState::kInvalidCheck) {
    messenger_.ShowError("Error! Incorrect credit term.");
    return false;
  } else if (months < CheckState::kMinimalCreditTerm) {
    messenger_.ShowError("Error! Credit term should be greater than 6 months.");
    return false;
  }
  return true;

  // return months > 0 && months <= CheckState::kMaximalCreditTerm;
}

void CLICreditDepartment::PerformCreditCalculations(int credit_sum) {
  SetCreditSum(credit_sum);
  SetCreditTerm(GetCreditTermFromUser());
  CalculateCredit();
}
