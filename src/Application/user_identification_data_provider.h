#ifndef USER_IDENTIFICATION_DATA_PROVIDER_H
#define USER_IDENTIFICATION_DATA_PROVIDER_H

#include <user_input.h>

#include <string>

class UserIdentificationDataProvider {
 public:
  std::string GetLoginFromUser();
  std::string GetPasswordFromUser();

 private:
  std::string GetDataFromUser();

  UserInput user_input_;
};

#endif  // USER_IDENTIFICATION_DATA_PROVIDER_H
