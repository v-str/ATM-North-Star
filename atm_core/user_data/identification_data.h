#ifndef IDENTIFICATION_DATA_H
#define IDENTIFICATION_DATA_H

#include <string>

class IdentificationData {
 public:
  IdentificationData();

  void SetLogin(const std::string& login);
  void SetPassword(const std::string& password);

  std::string Login();
  std::string Password();

 private:
  std::string login_;
  std::string password_;
};

#endif  // IDENTIFICATION_DATA_H
