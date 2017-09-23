#include <calculator_data_transformer.h>

#include <stdexcept>

int CalculatorDataTransformer::TransformIntegerData(const std::string &data) {
  try {
    return std::stoi(data);
  } catch (std::invalid_argument) {
    return kInvalidIntegerValue;
  } catch (std::out_of_range) {
    return kInvalidIntegerValue;
  }
}

double CalculatorDataTransformer::TransformFractionalData(
    const std::string &data) {
  try {
    return std::stod(data);
  } catch (std::invalid_argument) {
    return kInvalidDoubleValue;
  } catch (std::out_of_range) {
    return kInvalidDoubleValue;
  }
}
