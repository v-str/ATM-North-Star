#include <statement_manager.h>

#include <console_editor.h>
#include <statement_messenger.h>
#include <user_input_handler.h>

void StatementManager::RunStatement(int amount_of_cash) {
  StatementMessenger::ShowStatement(amount_of_cash);
  ConsoleEditor::IgnoreCinLine();
}
