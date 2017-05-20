#ifndef REGISTRATION_VERIFICATOR_H
#define REGISTRATION_VERIFICATOR_H

#include <string>

class RegistrationInspector {
 public:
  int InspectLogin(const std::string& login) const;
};

#endif  // REGISTRATION_VERIFICATOR_H
