#include "demo_user.h"
#include "initial_screen.h"
#include "system_utility.h"
#include "user.h"
#include "user_input.h"
#include "user_messenger.h"

int main() {
  UserMessenger user_messenger_;
  InitialScreen initial_screen;

  initial_screen.Logotype();
  initial_screen.Welcome();

  UserInput user_input;
  int choice = user_input.GetChoiceFromUser();

  User user;

  if (choice == 1) {
    DemoUser demo;
    demo.ShowDemoMode();
    if (demo.UserWantToRegistrate()) {
      user.Registration();
    }
  } else if (choice == 2) {
    user.Registration();

  } else {
    initial_screen.Error();
  }
  user_messenger_.WishAGoodDay();
}
