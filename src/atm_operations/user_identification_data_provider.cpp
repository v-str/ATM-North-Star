#include "user_identification_data_provider.h"

std::string UserIdentificationDataProvider::GetLoginFromUser() {
  return GetDataFromUser();
}

std::string UserIdentificationDataProvider::GetPasswordFromUser() {
  return GetDataFromUser();
}

std::string UserIdentificationDataProvider::GetDataFromUser() {
  return user_input_.GetDataFromUser();
}
