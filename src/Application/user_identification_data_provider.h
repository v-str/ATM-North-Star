#ifndef USER_IDENTIFICATION_DATA_PROVIDER_H
#define USER_IDENTIFICATION_DATA_PROVIDER_H

#include <string>

class UserIdentificationDataProvider {
  using string = std::string;

 public:
  string GetLoginFromUser();
  string GetPasswordFromUser();

 private:
  string GetDataFromUser();
};

#endif  // USER_IDENTIFICATION_DATA_PROVIDER_H
