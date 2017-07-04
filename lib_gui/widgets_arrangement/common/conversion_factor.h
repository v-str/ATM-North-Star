#ifndef CONVERSION_FACTOR_H
#define CONVERSION_FACTOR_H

class ConversionFactor {
 public:
  ConversionFactor();
  ConversionFactor(double x_coefficient, double y_coefficient);

  void SetXFactor(double x_coefficient);
  void SetYFactor(double y_coefficient);

  double XFactor() const;
  double YFactor() const;

 private:
  void XCheckOutOfRange(double x_factor);
  void YCheckOutOfRange(double y_factor);

  static constexpr double kMaximalFactor = 3.0;
  static constexpr double kMinimalFactor = 0.0;

  double x_axis_factor_ = 0.0;
  double y_axis_factor_ = 0.0;
};

#endif  // CONVERSION_FACTOR_H
