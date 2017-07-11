#include <conversion_factor.h>

ConversionFactor::ConversionFactor() {}

ConversionFactor::ConversionFactor(double x_axis_factor, double y_axis_factor) {
  XCheckOutOfRange(x_axis_factor);
  YCheckOutOfRange(y_axis_factor);
}

ConversionFactor::ConversionFactor(const ConversionFactor& conversion_factor) {
  x_axis_factor_ = conversion_factor.x_axis_factor_;
  y_axis_factor_ = conversion_factor.y_axis_factor_;
}

void ConversionFactor::SetXFactor(double x_axis_factor) {
  XCheckOutOfRange(x_axis_factor);
}

void ConversionFactor::SetYFactor(double y_axis_factor) {
  YCheckOutOfRange(y_axis_factor);
}

double ConversionFactor::XAxisFactor() const { return x_axis_factor_; }

double ConversionFactor::YAxisFactor() const { return y_axis_factor_; }

void ConversionFactor::XCheckOutOfRange(double x_axis_factor) {
  if (x_axis_factor > kMaximalFactor) {
    x_axis_factor_ = kMaximalFactor;
  } else if (x_axis_factor < kMinimalFactor) {
    x_axis_factor_ = kMinimalFactor;
  } else {
    x_axis_factor_ = x_axis_factor;
  }
}

void ConversionFactor::YCheckOutOfRange(double y_axis_factor) {
  if (y_axis_factor > kMaximalFactor) {
    y_axis_factor_ = kMaximalFactor;
  } else if (y_axis_factor < kMinimalFactor) {
    y_axis_factor_ = kMinimalFactor;
  } else {
    y_axis_factor_ = y_axis_factor;
  }
}
