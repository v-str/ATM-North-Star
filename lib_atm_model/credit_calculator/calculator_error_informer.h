#ifndef CALCULATOR_ERROR_INFORMER_H
#define CALCULATOR_ERROR_INFORMER_H

#include <string>
#include <vector>

class CalculatorErrorInformer {
 public:
  static void AddErrorText(const std::string& error_text);
  static std::vector<std::string> GetErrorsList();

  static void ResetErrorList();

 private:
  static std::vector<std::string> error_text_vector_;
};

#endif  // CALCULATOR_ERROR_INFORMER_H
