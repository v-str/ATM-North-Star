﻿#include <registration_messenger.h>

#include <console_editor_duplicate.h>

void RegistrationMessenger::ShowRegistrationScreen() {
  ConsoleEditorDuplicate::AddEmptyLineNTimes(2);
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteText(
      "\n\t   ********************\n"
      "\t   *   REGISTRATION   *\n"
      "\t   ********************\n\n");
}
