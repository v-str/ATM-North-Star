#ifndef OUTPUTSETUP_H
#define OUTPUTSETUP_H

#include "console_writer.h"
#include "multiwriter.h"
#include "text_writer.h"

#include <string>

class OutputSetup {
 public:
  static void SetupDefaultStream();

  static void SetupTwoStreamsForOutput();

 private:
  void SetVectorForOutput(std::unique_ptr<Writer> console_output,
                          std::unique_ptr<Writer> file_output);

  static std::string name_of_file_;
};

#endif  // OUTPUTSETUP_H
