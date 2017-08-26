#ifndef CONSOLE_ACCOUNT_INFORMER_H
#define CONSOLE_ACCOUNT_INFORMER_H

#include <string>
#include <vector>

class ConsoleAccountInformer {
 public:
  void SetAccountInfo(const std::vector<std::string>& account_info);

 private:
  std::vector<std::string> account_info_;
};

#endif  // CONSOLE_ACCOUNT_INFORMER_H
