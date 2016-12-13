#include "application.h"
#include "output_setup.h"

#include <fstream>
#include <iostream>

int main() {
  OutputSetup::SetupDoubleStream("Atm file.txt");

  Application app;
  app.RunProgram();
}
