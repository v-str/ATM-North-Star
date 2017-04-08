#include "credit_department.h"

int CreditDepartment::GetResultOfUserCheck(const AtmUser& user) const {
  return checker_.GetResultOfUserCheck(user);
}
