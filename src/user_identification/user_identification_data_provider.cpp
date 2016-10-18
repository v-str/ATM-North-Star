#include "user_identification_data_provider.h"

UserIdentificationDataProvider::string
UserIdentificationDataProvider::GetLoginFromUser() {
  registation_messenger_.ShowInitialLoginText();
  return GetDataFromUser();
  //  string login;
  //  getline(cin, login);
  //  return login;
}

UserIdentificationDataProvider::string
UserIdentificationDataProvider::GetPasswordFromUser() {
  registation_messenger_.ShowInitialPasswordText();
  return GetDataFromUser();
  //  string password;
  //  getline(cin, password);
  //  return password;
}

UserIdentificationDataProvider::string
UserIdentificationDataProvider::GetDataFromUser() {
  string user_data;
  getline(cin, user_data);
  return user_data;
}
