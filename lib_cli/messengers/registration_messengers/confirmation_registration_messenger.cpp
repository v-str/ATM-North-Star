#include <confirmation_registration_messenger.h>

#include <console_editor.h>

int ConfirmationRegistrationMessenger::string_length_ = 6;

void ConfirmationRegistrationMessenger::ShowConfirmationMessage(
    const std::string& login_string) {
  string_length_ = login_string.length();
}
