#include <iostream>

#include "screen.h"
#include "user.h"
#include "demo_user.h"

int main() {
  using std::cin;

  MnScreen();

  Welcome();

  int choice = 0;
  cin >> choice;

  if (choice == 1) {
    DemoUser demo;
    demo.ShowDemoMode();
  } else if (choice == 2) {
    AtmUser user;
    user.Registration();
  } else {
    Error();
  }
}
