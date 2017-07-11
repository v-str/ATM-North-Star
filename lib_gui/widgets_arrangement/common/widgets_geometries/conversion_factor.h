#ifndef CONVERSION_FACTOR_H
#define CONVERSION_FACTOR_H

class ConversionFactor {
 public:
  ConversionFactor();
  ConversionFactor(double x_axis_factor, double y_axis_factor);
  ConversionFactor(const ConversionFactor& conversion_factor);

  void SetXFactor(double x_axis_factor);
  void SetYFactor(double y_axis_factor);

  double XAxisFactor() const;
  double YAxisFactor() const;

 private:
  void XCheckOutOfRange(double x_axis_factor);
  void YCheckOutOfRange(double y_axis_factor);

  static constexpr double kMaximalFactor = 3.0;
  static constexpr double kMinimalFactor = 0.0;

  double x_axis_factor_ = 0.0;
  double y_axis_factor_ = 0.0;
};

#endif  // CONVERSION_FACTOR_H
