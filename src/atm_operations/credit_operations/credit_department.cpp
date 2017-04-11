#include "credit_department.h"

int CreditDepartment::ResultOfUserCheck(const AtmUser& user) const {
  return checker_.GetResultOfUserCheck(user);
}
