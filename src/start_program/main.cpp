#include "application.h"
#include "demo_user.h"
#include "initial_screen.h"

static const int kDemoMode = 1;
static const int kRegistration = 2;

int main() {
  UserMessenger user_messenger;
  InitialScreen initial_screen;

  initial_screen.Logotype();
  initial_screen.InitialMenu();

  UserInput user_input;
  int choice = user_input.GetChoiceFromUser();

  Application app;

  if (choice == kDemoMode) {
    DemoUser demo_mode;
    demo_mode.ShowDemoMode();
    if (demo_mode.UserWantToRegistrate()) {
      app.RunProgram();
    }
  } else if (choice == kRegistration) {
    app.RunProgram();

  } else {
    initial_screen.Error();
  }
  user_messenger.WishAGoodDay();
}
