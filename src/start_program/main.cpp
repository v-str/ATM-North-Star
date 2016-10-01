#include "application.h"
#include "demo_user.h"
#include "initial_screen.h"

static const int kDemoMode = 1;
static const int kRegistration = 2;

int main() {
  UserMessenger user_messenger_;
  InitialScreen initial_screen;

  initial_screen.Logotype();
  initial_screen.InitialMenuBox();

  UserInput user_input;
  int choice = user_input.GetChoiceFromUser();

  Application app;

  if (choice == kDemoMode) {
    DemoUser demo;
    demo.ShowDemoMode();
    if (demo.UserWantToRegistrate()) {
      app.Registration();
    }
  } else if (choice == kRegistration) {
    app.Registration();

  } else {
    initial_screen.Error();
  }
  user_messenger_.WishAGoodDay();
}
