#include "statement_messenger.h"

#include <iostream>

void StatementMessenger::ShowStatement(int cash, const string &spaces) const {
  std::cout << "\t##################\n"
               "\t#                #\n"
               "\t#  28 Green st.  #\n"
               "\t#   New - York   #\n"
               "\t#                #\n"
               "\t#   NORTH BANK   #\n"
               "\t#                #\n"
               "\t# Balance:       #\n"
               "\t#  $ "
            << cash << spaces << "#\n";
  std::cout << "\t#                #\n"
               "\t#  HAVE A NICE   #\n"
               "\t#      DAY       #\n"
               "\t#                #\n"
               "\t##################\n";
}
