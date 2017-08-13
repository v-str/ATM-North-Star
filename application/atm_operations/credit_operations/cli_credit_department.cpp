#include "cli_credit_department.h"

#include <string>

#include <credit_messenger.h>

void CLICreditDepartment::StartCreditOperationFor(AtmUser* user) {
  int result_of_check = ResultOfUserCheck(*user);

  if (result_of_check == CheckState::kPositiveCheck) {
    SuggestCredit(user);
  } else if (result_of_check == CheckState::kCreditExist) {
    CreditMessenger::RefuseACreditBasedOnAnotherCredit();
    CreditMessenger::ShowIncorrectCashInformation(user->Cash());
  } else if (result_of_check == CheckState::kInappropriateBalance) {
    CreditMessenger::RefuseACreditBasedOnCash(user->Cash());
  } else if (result_of_check == CheckState::kInvalidCheck) {
    CreditMessenger::UnavailableCreditState();
  }
}

void CLICreditDepartment::SuggestCredit(AtmUser* user) {
  CreditMessenger::NotifyAboutCredit();
  if (user_input_.GetValueFromUser() == kConsiderCredit) {
    if (ConsiderCredit(user->Cash())) {
      // ShowCredit();
    }
  }
}

bool CLICreditDepartment::ConsiderCredit(int user_cash) {
  int max_credit_sum = MaxCreditSum(user_cash);
  int credit_sum = 0;
  CreditMessenger::ShowCreditConditions(max_credit_sum);
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
  CreditMessenger::ShowInfoAboutCreditSum();
  do {
    CreditMessenger::SuggestEnterCreditSum();
    user_credit_sum = user_input_.GetValueFromUser();
  } while (!IsValid(user_credit_sum, max_credit_sum));

  return user_credit_sum;
}

int CLICreditDepartment::GetCreditTermFromUser() const {
  int months = 0;
  CreditMessenger::ShowInfoAboutCreditTerm();
  do {
    CreditMessenger::SuggestEnterCreditTerm();
    months = user_input_.GetValueFromUser();
  } while (!IsValid(months));
  return months;
}

bool CLICreditDepartment::IsValid(int credit_sum, int max_credit_sum) const {
  if (credit_sum > max_credit_sum) {
    CreditMessenger::ShowError("Exceeding of desired credit sum");
    return false;
  }
  if (credit_sum == CheckState::kInvalidCreditSum) {
    CreditMessenger::ShowError("Incorrect credit sum");
    return false;
  }
  if (credit_sum < CheckState::kMinimalCreditSum) {
    std::string error_message = "Credit sum should be greater than $" +
                                std::to_string(CheckState::kMinimalCreditSum);
    CreditMessenger::ShowError(error_message);
    return false;
  }
  CreditMessenger::ShowDataConfirmation();
  return true;
}

bool CLICreditDepartment::IsValid(int month) const {
  if (month > CheckState::kMaximalCreditTerm) {
    CreditMessenger::ShowError("Exceeding of desired credit term");
    return false;
  }
  if (month == CheckState::kInvalidCreditTerm) {
    CreditMessenger::ShowError("Incorrect credit term");
    return false;
  }
  if (month < CheckState::kMinimalCreditTerm) {
    std::string error_message = "Credit term should be greater than " +
                                std::to_string(CheckState::kMinimalCreditTerm) +
                                " months";
    CreditMessenger::ShowError(error_message);
    return false;
  }
  CreditMessenger::ShowDataConfirmation();
  return true;
}

void CLICreditDepartment::PerformCreditCalculations(int credit_sum) {
  SetCreditSum(credit_sum);
  SetCreditTerm(GetCreditTermFromUser());
  CalculateCredit();
}
