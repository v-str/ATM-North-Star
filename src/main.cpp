#include <iostream>
#include <limits>

#include "demo_user.h"
#include "screen.h"
#include "system_utility.h"
#include "user.h"
#include "user_input.h"

int main() {
  using std::cin;

  MnScreen();

  Welcome();
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
    Error();
  }
  user.WishGoodDay();
}
