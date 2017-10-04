#include <registration_messenger.h>

#include <console_editor.h>

void RegistrationMessenger::ShowRegistrationLogo() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "\n"
      "#######################################################\n"
      "#                                                     #\n"
      "#                   REGISTRATION                      #\n"
      "#                                                     #\n"
      "#######################################################\n");
}

void RegistrationMessenger::ShowRegistrationReference() {
  ConsoleEditor::WriteText(
      "#                                                     #\n"
      "# This notice help you perform registration, please   #\n"
      "# read it carefully:                                  #\n"
      "#                                                     #\n"
      "# 1. Length of login: 6-35 latin symbols inclusively  #\n"
      "# 2. Length of password: 6 symbols                    #\n"
      "# 3. Length of tooltip: no more that 50 symbols       #\n"
      "#                                                     #\n"
      "# 5. Login must not contain special symbols           #\n"
      "# ( e.g. ; - % # ! and so on)                         #\n"
      "#                                                     #\n"
      "# 6. Password must not contain space symbols          #\n"
      "#                                                     #\n"
      "# 7. Password may contain both latin alphabet symbols #\n"
      "#    and arabic digits                                #\n"
      "#                                                     #\n"
      "#######################################################\n\n"
      "    1. Start registration\n"
      "     2. Return to initial menu\n"
      "      3. Quit\n\n"
      "Enter: ");
}

void RegistrationMessenger::ShowControlQuestionNotification() {
  ConsoleEditor::WriteText("#");
}

void RegistrationMessenger::ShowLoginTitle() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\n\n\tLogin: ", kTitleDelay);
}

void RegistrationMessenger::ShowPasswordTitle() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\tPassword: ", kTitleDelay);
}

void RegistrationMessenger::IncorrectRegistrationNotification() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "The data was inputted in a wrong way...\n\n"
      "  1. Re-enter registration data\n"
      "   2. Initial menu\n"
      "    3. Quit\n\n"
      "Enter: ");
}

void RegistrationMessenger::ShowConfirmationMessage() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "Registration data confirmed...\n\n"
      "  1. Perform registration\n"
      "   2. Initial menu\n"
      "    3. Quit\n\n"
      "Enter: ");
}
