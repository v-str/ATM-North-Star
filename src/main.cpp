#include <iostream>

#include "screen.h"
#include "user.h"

int main() {
  using std::cin;

  MnScreen();

  Welcome();

  int choice = 0;
  cin >> choice;

  if (choice == 1) {
    AtmUser demo("Demo mode", "0000", 0.0, 0, 0.0, 0);
    demo.DemoMode();
  } else if (choice == 2) {
    AtmUser one;
    one.Registration();
  } else if (choice == 3) {
    AtmUser two("Lol", "1234", 0.0, 0, 0.0, 0);
    two.ShowMenuNonRecursive();
  } else {
    Error();
  }
}
