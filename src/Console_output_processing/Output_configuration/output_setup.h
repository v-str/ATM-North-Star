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
  static std::string name_of_file_;
};

#endif  // OUTPUTSETUP_H
