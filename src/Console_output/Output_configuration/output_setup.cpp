#include "output_setup.h"

#include "console_writer.h"
#include "text_writer.h"

std::string OutputSetup::name_of_file_ = "ATM.txt";

void OutputSetup::SetupDefaultStream() {
  std::unique_ptr<ConsoleWriter> console_writer(new ConsoleWriter);
  TextWriter::SetWriter(std::move(console_writer));
}

void OutputSetup::SetupTwoStreamsForOutput() {
  std::unique_ptr<ConsoleWriter> console_writer(new ConsoleWriter);
  std::unique_ptr<FileWriter> file_writer(new FileWriter(name_of_file_));

  SetVectorForOutput(std::move(console_writer), std::move(file_writer));
}

void OutputSetup::SetVectorForOutput(std::unique_ptr<Writer> console_output,
                                     std::unique_ptr<Writer> file_output) {
  std::vector<std::unique_ptr<Writer> > output_vector;

  output_vector.push_back(std::move(console_output));
  output_vector.push_back(std::move(file_output));

  SetMultistream(std::move(output_vector));
}

void OutputSetup::SetMultistream(
    std::vector<std::unique_ptr<Writer> > output_vector) {
  std::unique_ptr<Writer> multiwriter(
      new MultiWriter(std::move(output_vector)));

  TextWriter::SetWriter(std::move(multiwriter));
}
