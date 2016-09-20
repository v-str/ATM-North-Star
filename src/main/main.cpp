#include "demo_user.h"
#include "initial_screen.h"
#include "application.h"

int main() {
  UserMessenger user_messenger_;
  InitialScreen initial_screen;

  initial_screen.Logotype();
  initial_screen.Welcome();

  UserInput user_input;
  int choice = user_input.GetChoiceFromUser();

  Application app;

  if (choice == 1) {
    DemoUser demo;
    demo.ShowDemoMode();
    if (demo.UserWantToRegistrate()) {
      app.Registration();
    }
  } else if (choice == 2) {
    app.Registration();

  } else {
    initial_screen.Error();
  }
  user_messenger_.WishAGoodDay();
}
