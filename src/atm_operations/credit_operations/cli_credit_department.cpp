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

void CLICreditDepartment::ConsiderCredit(AtmUser* user) {}
