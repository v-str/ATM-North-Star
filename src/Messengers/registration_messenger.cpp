#include "registration_messenger.h"

#include <iostream>
#include <string>
#include "console_editor.h"
#include "text_writer.h"

void RegistrationMessenger::ShowRegistrationScreen() {
  ConsoleEditor::ClearScreen();

  std::string text =
      "\n\t   ********************\n"
      "\t   *   REGISTRATION   *\n"
      "\t   ********************\n\n";

  TextWriter::Write(text);
}
