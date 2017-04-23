#include "cli_credit_department.h"

#include <string>

void CLICreditDepartment::StartCreditOperationFor(AtmUser* user) {
  int result_of_check = ResultOfUserCheck(*user);

  if (result_of_check == CheckState::kPositiveCheck) {
    SuggestCredit(user);
  } else if (result_of_check == CheckState::kCreditExist) {
    messenger_.RefuseACreditBasedOnAnotherCredit();
    messenger_.ShowIncorrectCashInformation(user->Cash());
  } else if (result_of_check == CheckState::kInappropriateBalance) {
    messenger_.RefuseACreditBasedOnCash(user->Cash());
  } else if (result_of_check == CheckState::kInvalidCheck) {
    messenger_.UnavailableCreditState();
  }
}

void CLICreditDepartment::SuggestCredit(AtmUser* user) {
  messenger_.NotifyAboutCredit();
  if (user_input_.GetValueFromUser() == kConsiderCredit) {
    if (ConsiderCredit(user->Cash())) {
      // ShowCredit();
    }
  }
}

bool CLICreditDepartment::ConsiderCredit(int user_cash) {
  int max_credit_sum = MaxCreditSum(user_cash);
  int credit_sum = 0;
  messenger_.ShowCreditConditions(max_credit_sum);
  int user_choice = user_input_.GetValueFromUser();
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

int CLICreditDepartment::GetCreditSumFromUser(int max_credit_sum) const {
  int user_credit_sum = 0;
  messenger_.ShowInfoAboutCreditSum();
  do {
    messenger_.SuggestEnterCreditSum();
    user_credit_sum = user_input_.GetValueFromUser();
  } while (!IsValid(user_credit_sum, max_credit_sum));

  return user_credit_sum;
}

int CLICreditDepartment::GetCreditTermFromUser() const {
  int months = 0;
  messenger_.ShowInfoAboutCreditTerm();
  do {
    messenger_.SuggestEnterCreditTerm();
    months = user_input_.GetValueFromUser();
  } while (!IsValid(months));
  return months;
}

bool CLICreditDepartment::IsValid(int credit_sum, int max_credit_sum) const {
  if (credit_sum > max_credit_sum) {
    messenger_.ShowError("Exceeding of desired credit sum");
    return false;
  }
  if (credit_sum == CheckState::kInvalidCreditSum) {
    messenger_.ShowError("Incorrect credit sum");
    return false;
  }
  if (credit_sum < CheckState::kMinimalCreditSum) {
    std::string error_message = "Credit sum should be greater than $" +
                                std::to_string(CheckState::kMinimalCreditSum);
    messenger_.ShowError(error_message);
    return false;
  }
  messenger_.ShowDataConfirmation();
  return true;
}

bool CLICreditDepartment::IsValid(int month) const {
  if (month > CheckState::kMaximalCreditTerm) {
    messenger_.ShowError("Exceeding of desired credit term");
    return false;
  }
  if (month == CheckState::kInvalidCreditTerm) {
    messenger_.ShowError("Incorrect credit term");
    return false;
  }
  if (month < CheckState::kMinimalCreditTerm) {
    std::string error_message = "Credit term should be greater than " +
                                std::to_string(CheckState::kMinimalCreditTerm) +
                                " months";
    messenger_.ShowError(error_message);
    return false;
  }
  messenger_.ShowDataConfirmation();
  return true;
}

void CLICreditDepartment::PerformCreditCalculations(int credit_sum) {
  SetCreditSum(credit_sum);
  SetCreditTerm(GetCreditTermFromUser());
  CalculateCredit();
}
