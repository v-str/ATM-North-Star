#include <registration_reporter.h>

#include <registration_status_messenger.h>

void RegistrationReporter::ShowLoginReport(RegistrationStatus login_status) {
  switch (login_status) {
    case kCorrectLogin:
      RegistrationStatusMessenger::CorrectLoginMessage();
      break;
    case kShortLogin:
      RegistrationStatusMessenger::LoginLengthStatus(
          RegistrationStatusMessenger::kShortLoginLength);
      break;
    case kLongLogin:
      RegistrationStatusMessenger::LoginLengthStatus(
          RegistrationStatusMessenger::kLongLoginLength);
      break;
    case kSpecialSymbols:
      RegistrationStatusMessenger::LoginContainSpecialSymbol();
      break;
    case kBeginWithSpace:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kBeginWithSpace);
      break;
    case kEndWithSpace:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kEndWithSpace);
      break;
    case kAdjacentSpaces:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kAdjecentSpaces);
      break;
    case kContainOnlyDigits:
      RegistrationStatusMessenger::LoginContainOnlyDigits();
      break;
    case kEmptyString:
      RegistrationStatusMessenger::LoginEmpty();
      break;
    default:
      break;
  }
}

void RegistrationReporter::ShowPasswordReport(
    RegistrationStatus password_status) {
  switch (password_status) {
    case kCorrectPassword:
      RegistrationStatusMessenger::CorrectPasswordMessage();
      break;
    case kShortPassword:
      RegistrationStatusMessenger::PasswordLength(
          RegistrationStatusMessenger::kShortPasswordLength);
      break;
    case kLongPassword:
      RegistrationStatusMessenger::PasswordLength(
          RegistrationStatusMessenger::kLongPasswordLength);
      break;
    case kContainSpaceSymbol:
      RegistrationStatusMessenger::PasswordContainSpaceSymbol();
      break;
    case kEmptyString:
      RegistrationStatusMessenger::PasswordEmpty();
      break;
    default:
      break;
  }
  RegistrationStatusMessenger::AddEmptyLines(2);
}
