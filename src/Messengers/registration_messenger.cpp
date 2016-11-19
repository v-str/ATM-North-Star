#include "registration_messenger.h"

#include <iostream>
#include <string>
#include "console_editor.h"
#include "text_writer.h"

void RegistrationMessenger::ShowRegistrationScreen() {
  ConsoleEditor::ClearScreen();

  std::string text =
      "\n\t\t   ********************\n"
      "\t\t   *   REGISTRATION   *\n"
      "\t\t   ********************\n";

  TextWriter::Write(text);
}
