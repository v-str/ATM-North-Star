#include "application.h"
#include "demo_user.h"
#include "initial_screen.h"

const int kdemo_mode = 1;
const int kregistration = 2;

int main() {
  UserMessenger user_messenger_;
  InitialScreen initial_screen;

  initial_screen.Logotype();
  initial_screen.Welcome();

  UserInput user_input;
  int choice = user_input.GetChoiceFromUser();

  Application app;

  if (choice == kdemo_mode) {
    DemoUser demo;
    demo.ShowDemoMode();
    if (demo.UserWantToRegistrate()) {
      app.Registration();
    }
  } else if (choice == kregistration) {
    app.Registration();

  } else {
    initial_screen.Error();
  }
  user_messenger_.WishAGoodDay();
}
