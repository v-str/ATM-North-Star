#include "registration_inspector.h"

ATM::LoginStatus RegistrationInspector::InspectLoginString(
    const std::string& login) const {
  return ATM::LoginStatus::kCorrectLogin;
}
