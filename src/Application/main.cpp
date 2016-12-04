#include "application.h"
#include "consolewriter.h"
#include "multiwriter.h"
#include "text_writer.h"

#include <fstream>
#include <iostream>

int main() {
  std::vector<std::unique_ptr<Writer> > output_vector;

  std::unique_ptr<FileWriter> file_writer(new FileWriter);

  file_writer->OpenFile("Atm_operations.txt");

  std::unique_ptr<ConsoleWriter> console_writer(new ConsoleWriter);

  output_vector.push_back(std::move(file_writer));
  output_vector.push_back(std::move(console_writer));

  std::unique_ptr<Writer> multiwriter(
      new MultiWriter(std::move(output_vector)));

  TextWriter::SetWriter(std::move(multiwriter));

  Application app;
  app.RunProgram();
}
