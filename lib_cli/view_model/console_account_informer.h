#ifndef CONSOLE_ACCOUNT_INFORMER_H
#define CONSOLE_ACCOUNT_INFORMER_H

#include <string>
#include <vector>

class ConsoleAccountInformer {
 public:
  ConsoleAccountInformer();

  void SetAccountInfo(const std::vector<std::string>& account_info);

  void ShowAccountInfo() const;

 private:
  void FillTitles();

  std::vector<std::string> account_info_;
  std::vector<std::string> info_title_;
};

#endif  // CONSOLE_ACCOUNT_INFORMER_H
