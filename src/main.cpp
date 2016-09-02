#include <iostream>
#include <limits>

#include "demo_user.h"
#include "initial_screen.h"
#include "system_utility.h"
#include "user.h"
#include "user_input.h"

int main() {
  using std::cin;

  InitialScreen initial_screen;
  initial_screen.Logotype();
  initial_screen.Welcome();

  UserInput user_input;
  int choice = user_input.GetChoiceFromUser();

  AtmUser user;

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
  user.WishGoodDay();
}
