#include <iostream>

#include "demo_user.h"
#include "screen.h"
#include "user.h"

static const int k_demo_mode = 1;
static const int k_registration_mode = 2;

int main() {
  using std::cin;

  MnScreen();

  Welcome();

  int choice = 0;

  cin >> choice;

  AtmUser user;
  if (choice == k_demo_mode) {
    DemoUser demo;
    demo.ShowDemoMode();
    if (demo.UserWantToRegistrate()) {
      user.Registration();
    }
  } else if (choice == k_registration_mode) {
    user.Registration();

  } else {
    Error();
  }
  user.WishGoodDay();
}
