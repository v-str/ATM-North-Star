#include <text_writer.h>
#include "application.h"

#include <fstream>
#include <iostream>

int main() {
  std::ofstream stream_output;
  stream_output.open("Atm_file.txt");
  stream_output << "Atm file:" << std::endl << std::endl;

  //TextWriter::SetOutputStream(&stream_output);
  Application app;
  app.RunProgram();

  stream_output.close();
}
