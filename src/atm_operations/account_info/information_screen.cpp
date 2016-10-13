#include "information_screen.h"

void InformationScreen::DisplayStrip() {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
}
