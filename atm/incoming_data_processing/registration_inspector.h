#ifndef REGISTRATION_VERIFICATOR_H
#define REGISTRATION_VERIFICATOR_H

#include <string>

#include <registration_status.h>

class RegistrationInspector {
 public:
  ATM::LoginStatus InspectLoginString(const std::string& login) const;

 private:
  bool IsLoginShort(const std::string& login) const;
  bool IsLoginLong(const std::string& login) const;
};

#endif  // REGISTRATION_VERIFICATOR_H
