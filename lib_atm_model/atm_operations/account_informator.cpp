#include <account_informator.h>

#include <atm_user.h>
#include <user_data_converter.h>

std::string AccountInformator::login_ = "not specified";
std::string AccountInformator::cash_ = "not specified";

void AccountInformator::UpdataUserData(const AtmUser& user) {
  login_ = user.Login();
  cash_ = UserDataConverter::ConvertDataToString(user.Cash());
}

std::string AccountInformator::Login() { return login_; }

std::string AccountInformator::Cash() { return cash_; }
