#include <conversion_factor.h>

ConversionFactor::ConversionFactor() {}

ConversionFactor::ConversionFactor(double x_coefficient, double y_coefficient) {
  XCheckOutOfRange(x_coefficient);
  YCheckOutOfRange(y_coefficient);
}

void ConversionFactor::SetXFactor(double x_coefficient) {
  XCheckOutOfRange(x_coefficient);
}

void ConversionFactor::SetYFactor(double y_coefficient) {
  YCheckOutOfRange(y_coefficient);
}

double ConversionFactor::XFactor() const { return x_axis_factor_; }

double ConversionFactor::YFactor() const { return y_axis_factor_; }

void ConversionFactor::XCheckOutOfRange(double x_factor) {
  if (x_factor > kMaximalFactor) {
    x_axis_factor_ = kMaximalFactor;
  } else if (x_factor < kMinimalFactor) {
    x_axis_factor_ = kMinimalFactor;
  } else {
    x_axis_factor_ = x_factor;
  }
}

void ConversionFactor::YCheckOutOfRange(double y_factor) {
  if (y_factor > kMaximalFactor) {
    y_axis_factor_ = kMaximalFactor;
  } else if (y_factor < kMinimalFactor) {
    y_axis_factor_ = kMinimalFactor;
  } else {
    y_axis_factor_ = y_factor;
  }
}
