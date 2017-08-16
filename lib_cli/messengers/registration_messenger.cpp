#include <registration_messenger.h>

#include <console_editor.h>

void RegistrationMessenger::ShowRegistrationLogo() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "\n\t   ********************\n"
      "\t   *   REGISTRATION   *\n"
      "\t   ********************\n\n");
}

void RegistrationMessenger::ShowRegistrationReference() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "  This notice help you perform registration, please read it "
      "carefully:\n\n"
      " 1. Length of the login must be no less than 6 and\n"
      "    no more than 35 latin symbols.\n"
      " 2. Login must not contain special symbols ( e.g. ; - % * and so on) "
      "and\n"
      "    consist of latin alphabet symbols and arabic digits.\n"
      " 3. Length of password must be stricly 6 symbols.\n"
      " 4. Password must not contain space symbols.\n"
      " 5. Password may contain both latin alphabet symbols and arabic "
      "digits.\n\n\n"
      " 1. Start registration\n"
      " 2. Quit ( or press q )\n"
      " Enter: ");
}

void RegistrationMessenger::ShowIncorrectInput() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n Incorrect input, please enter 1 for registration or\n"
      " press 2 to exit program ( or press q )\n"
      " Enter: ");
}
