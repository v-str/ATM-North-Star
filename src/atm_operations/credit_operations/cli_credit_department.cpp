#include "cli_credit_department.h"

void CLICreditDepartment::StartCreditOperationFor(AtmUser* user) {
  const int result_of_check = GetResultOfUserCheck(*user);

  if (result_of_check == kPositiveCheck) {
  } else if (result_of_check == kCreditExist) {
    messenger_.RefuseACreditBasedOnAnotherCredit();
    messenger_.ShowIncorrectCashInformation(user->GetCash());
  } else if (result_of_check == kInappropriateBalance) {
    messenger_.RefuseACreditBasedOnCash(user->GetCash());
  }
}
