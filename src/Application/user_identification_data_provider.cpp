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
  return user_input_.GetDataFromUser();
}
