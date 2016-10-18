#include "user_identification_data_provider.h"

UserIdentificationDataProvider::string
UserIdentificationDataProvider::GetLoginFromUser() {
  registation_messenger_.ShowInitialLoginText();
  return GetDataFromUser();
}

UserIdentificationDataProvider::string
UserIdentificationDataProvider::GetPasswordFromUser() {
  registation_messenger_.ShowInitialPasswordText();
  return GetDataFromUser();
}

UserIdentificationDataProvider::string
UserIdentificationDataProvider::GetDataFromUser() {
  string user_data;
  getline(cin, user_data);
  return user_data;
}
