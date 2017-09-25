#include <calculator_error_informer.h>

std::vector<std::string> CalculatorErrorInformer::error_text_vector_;

void CalculatorErrorInformer::AddErrorText(const std::string& error_text) {
  error_text_vector_.push_back(error_text);
}

std::vector<std::string> CalculatorErrorInformer::GetErrorsList() {
  return error_text_vector_;
}

void CalculatorErrorInformer::ResetErrorList() {
  error_text_vector_.erase(error_text_vector_.begin(),
                           error_text_vector_.end());
}
