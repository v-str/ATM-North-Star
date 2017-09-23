#ifndef CALCULATOR_DATA_TRANSFORMER_H
#define CALCULATOR_DATA_TRANSFORMER_H

#include <string>

class CalculatorDataTransformer {
 public:
  static int TransformIntegerData(const std::string& data);
  static double TransformFractionalData(const std::string& data);

 private:
  static constexpr int kInvalidIntegerValue = -1;
  static constexpr double kInvalidDoubleValue = -1.0;
};

#endif  // CALCULATOR_DATA_TRANSFORMER_H
