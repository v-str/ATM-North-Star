#include <quit_menu_handler.h>

#include <user_input_processor.h>
#include <user_messenger.h>

bool QuitMenuHandler::GetQuitResult() {
  UserMessenger::ShowQuitMenu();
  bool quit_result = true;
  int user_choice = 0;
  for (;;) {
    user_choice = UserInputProcessor::GetUserInput();
    if (user_choice == kMainMenu) {
      quit_result = false;
      break;
    } else if (user_choice == kQuit || user_choice == kSumMenuQuit) {
      break;
    } else {
      UserMessenger::ShowIncorrectInput();
    }
  }

  return quit_result;
}
