#include "output_setup.h"

std::string OutputSetup::name_of_file_ = "ATM.txt";

void OutputSetup::SetupDefaultStream() {
  std::unique_ptr<ConsoleWriter> console_writer(new ConsoleWriter);
  TextWriter::SetWriter(std::move(console_writer));
}

void OutputSetup::SetupTwoStreamsForOutput() {
  std::unique_ptr<ConsoleWriter> console_writer(new ConsoleWriter);
  std::unique_ptr<FileWriter> file_writer(new FileWriter(name_of_file_));

  std::vector<std::unique_ptr<Writer> > output_vector;
  output_vector.push_back(std::move(console_writer));
  output_vector.push_back(std::move(file_writer));

  std::unique_ptr<Writer> multiwriter(
      new MultiWriter(std::move(output_vector)));

  TextWriter::SetWriter(std::move(multiwriter));
}
