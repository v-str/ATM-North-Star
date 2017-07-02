#include <shift_coefficient.h>

ShiftCoefficient::ShiftCoefficient() {}

ShiftCoefficient::ShiftCoefficient(double x_coefficient, double y_coefficient) {
  XCheckOutOfRange(x_coefficient);
  YCheckOutOfRange(y_coefficient);
}

void ShiftCoefficient::SetXCoefficient(double x_coefficient) {
  XCheckOutOfRange(x_coefficient);
}

void ShiftCoefficient::SetYCoefficient(double y_coefficient) {
  YCheckOutOfRange(y_coefficient);
}

double ShiftCoefficient::XCoefficient() const { return x_coefficient_; }

double ShiftCoefficient::YCoefficient() const { return y_coefficient_; }

void ShiftCoefficient::XCheckOutOfRange(double x_coefficient) {
  if (x_coefficient > kMaximalCoefficient) {
    x_coefficient_ = kMaximalCoefficient;
  } else if (x_coefficient < kMinimalCoefficient) {
    x_coefficient_ = kMinimalCoefficient;
  } else {
    x_coefficient_ = x_coefficient;
  }
}

void ShiftCoefficient::YCheckOutOfRange(double y_coefficient) {
  if (y_coefficient > kMaximalCoefficient) {
    y_coefficient_ = kMaximalCoefficient;
  } else if (y_coefficient < kMinimalCoefficient) {
    y_coefficient_ = kMinimalCoefficient;
  } else {
    y_coefficient_ = y_coefficient;
  }
}
