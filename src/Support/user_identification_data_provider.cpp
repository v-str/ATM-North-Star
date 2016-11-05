#include "user_identification_data_provider.h"

#include "iostream"

UserIdentificationDataProvider::string
UserIdentificationDataProvider::GetLoginFromUser() {
  return GetDataFromUser();
}

UserIdentificationDataProvider::string
UserIdentificationDataProvider::GetPasswordFromUser() {
  return GetDataFromUser();
}

UserIdentificationDataProvider::string
UserIdentificationDataProvider::GetDataFromUser() {
  string user_data;
  getline(std::cin, user_data);
  return user_data;
}
