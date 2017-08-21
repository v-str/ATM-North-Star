#include <confirmation_registration_messenger.h>

#include <console_editor.h>

int ConfirmationRegistrationMessenger::maximal_string_length_ = 6;

void ConfirmationRegistrationMessenger::ShowConfirmationMessage(
    const std::string& login_string, const std::string& password_string) {
  maximal_string_length_ = login_string.length();
}
