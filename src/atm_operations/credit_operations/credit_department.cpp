#include "credit_department.h"

bool CreditDepartment::IsCreditAllowed(const AtmUser& user) const {
  return checker_.IsCheckPositive(user);
}
