#include <iostream>

#include "demo_user.h"
#include "screen.h"
#include "user.h"

int main() {
  using std::cin;

  MnScreen();

  Welcome();

  int choice = 0;

  cin >> choice;

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
