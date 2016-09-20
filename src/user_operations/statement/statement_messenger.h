#ifndef STATEMENT_MESSENGER_H
#define STATEMENT_MESSENGER_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;

class StatementMessenger {
  using string = std::string;

 public:
  void ShowStatement(int cash, const string &spaces) const;
};

#endif  // STATEMENT_MESSENGER_H
