#include <account_informator.h>

#include <atm_user.h>
#include <user_data_converter.h>

std::string AccountInformator::login_ = "not specified";
std::string AccountInformator::cash_ = "not specified";
std::string AccountInformator::password_tooltip_ = "not specified";

void AccountInformator::UpdataUserData(const AtmUser& user) {
  login_ = user.Login();
  cash_ = UserDataConverter::ConvertDataToString(user.Cash());
  password_tooltip_ = user.PasswordTooltip();
}

std::string AccountInformator::Login() { return login_; }

std::string AccountInformator::Cash() { return cash_; }

std::string AccountInformator::PasswordTooltip() { return password_tooltip_; }
