#ifndef USER_IDENTIFICATION_DATA_PROVIDER_H
#define USER_IDENTIFICATION_DATA_PROVIDER_H

#include "iostream"
#include "string"

#include "registration_messenger.h"

using std::cin;

class UserIdentificationDataProvider {
  using string = std::string;

 public:
  string GetLoginFromUser();
  string GetPasswordFromUser();

  string GetDataFromUser();

 private:
  RegistrationMessenger registation_messenger_;
};

#endif  // USER_IDENTIFICATION_DATA_PROVIDER_H
