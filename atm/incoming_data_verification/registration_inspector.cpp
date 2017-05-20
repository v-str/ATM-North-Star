#include <registration_inspector.h>

#include <registration_standard.h>

ATM::LoginStatus RegistrationInspector::InspectLoginString(
    const std::string& login) const {
  if (IsLoginShort(login)) {
    return ATM::LoginStatus::kShortLogin;
  }

  return ATM::LoginStatus::kCorrectLogin;
}

bool RegistrationInspector::IsLoginShort(const std::string& login) const {
  return login.length() < RegistrationStandard::MinLoginLength();
}
