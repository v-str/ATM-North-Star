#include "statement_messenger.h"

#include <iostream>

void StatementMessenger::ShowStatement(int cash,
                                       const std::string &spaces) const {
  console_editor_.WriteText(
      "\t##################\n"
      "\t#                #\n"
      "\t#  28 Green st.  #\n"
      "\t#   New - York   #\n"
      "\t#                #\n"
      "\t#   NORTH BANK   #\n"
      "\t#                #\n"
      "\t# Balance:       #\n"
      "\t#  $ " +
      std::to_string(cash) + spaces + "#\n" +
      "\t#                #\n"
      "\t#  HAVE A NICE   #\n"
      "\t#      DAY       #\n"
      "\t#                #\n"
      "\t##################\n");
}
