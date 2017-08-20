#include <registration_reporter.h>

#include <registration_status_messenger.h>

void RegistrationReporter::ShowLoginReport(STATUS login_status) {
  switch (login_status) {
    case STATUS::kCorrectLogin:
      RegistrationStatusMessenger::CorrectLoginMessage();
      break;
    case STATUS::kShortLogin:
      RegistrationStatusMessenger::LoginLengthStatus(
          RegistrationStatusMessenger::kShortLoginLength);
      break;
    case STATUS::kLongLogin:
      RegistrationStatusMessenger::LoginLengthStatus(
          RegistrationStatusMessenger::kLongLoginLength);
      break;
    case STATUS::kSpecialSymbols:
      RegistrationStatusMessenger::LoginContainSpecialSymbol();
      break;
    case STATUS::kBeginWithSpace:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kBeginWithSpace);
      break;
    case STATUS::kEndWithSpace:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kEndWithSpace);
      break;
    case STATUS::kAdjacentSpaces:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kAdjecentSpaces);
      break;
    case STATUS::kContainOnlyDigits:
      RegistrationStatusMessenger::LoginContainOnlyDigits();
      break;
    case STATUS::kEmptyString:
      RegistrationStatusMessenger::LoginEmpty();
      break;
    default:
      break;
  }
}

void RegistrationReporter::ShowPasswordReport(STATUS password_status) {
  switch (password_status) {
    case STATUS::kCorrectPassword:
      RegistrationStatusMessenger::CorrectPasswordMessage();
      break;
    case STATUS::kShortPassword:
      RegistrationStatusMessenger::PasswordLength(
          RegistrationStatusMessenger::kShortPasswordLength);
      break;
    case STATUS::kLongPassword:
      RegistrationStatusMessenger::PasswordLength(
          RegistrationStatusMessenger::kLongPasswordLength);
      break;
    case STATUS::kContainSpaceSymbol:
      RegistrationStatusMessenger::PasswordContainSpaceSymbol();
      break;
    case STATUS::kEmptyString:
      RegistrationStatusMessenger::PasswordEmpty();
      break;
    default:
      break;
  }
  RegistrationStatusMessenger::AddEmptyLines(2);
}
