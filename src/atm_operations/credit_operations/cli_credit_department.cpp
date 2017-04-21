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
  } while (!IsValid(user_credit_sum, max_credit_sum, CheckState::kInvalidCheck,
                    CheckState::kMinimalCreditSum, "sum", "$500"));

  return user_credit_sum;
}

int CLICreditDepartment::GetCreditTermFromUser() const {
  int months = 0;
  messenger_.ShowInfoAboutCreditTerm();
  do {
    messenger_.SuggestEnterCreditTerm();
    months = input_.GetValueFromUser();
  } while (!IsValid(months, CheckState::kMaximalCreditTerm,
                    CheckState::kInvalidCheck, CheckState::kMinimalCreditTerm,
                    "term", "6 month"));
  return months;
}

bool CLICreditDepartment::IsValid(int comparable_variable,
                                  int condition_1,
                                  int condition_2,
                                  int condition_3,
                                  const std::string& phrase_1,
                                  const std::string& phrase_2) const {
  if (comparable_variable > condition_1) {
    messenger_.ShowError("Error! Exceeding of desired credit " + phrase_1);
    return false;
  } else if (comparable_variable == condition_2) {
    messenger_.ShowError("Error! Incorrect credit " + phrase_1);
    return false;
  } else if (comparable_variable < condition_3) {
    messenger_.ShowError("Error! Credit " + phrase_1 +
                         " should be greater than " + phrase_2);
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
