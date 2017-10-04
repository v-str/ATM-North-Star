#ifndef IDENTIFICATION_DATA_H
#define IDENTIFICATION_DATA_H

#include <string>

class IdentificationData {
 public:
  IdentificationData();

  void SetLogin(const std::string& login);
  void SetPassword(const std::string& password);
  void SetControlQuestion(const std::string& control_question);
  void SetControlAnswer(const std::string& contol_answer);

  std::string Login() const;
  std::string Password() const;
  std::string ControlQuestion() const;
  std::string ControlAnswer() const;

 private:
  std::string login_;
  std::string password_;
  std::string control_question_;
  std::string control_answer_;
};

#endif  // IDENTIFICATION_DATA_H
