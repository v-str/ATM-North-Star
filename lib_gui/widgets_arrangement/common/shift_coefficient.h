#ifndef SHIFT_COEFFICIENT_H
#define SHIFT_COEFFICIENT_H

class ShiftCoefficient {
 public:
  ShiftCoefficient();
  ShiftCoefficient(double x_coefficient, double y_coefficient);

  void SetXCoefficient(double x_coefficient);
  void SetYCoefficient(double y_coefficient);

  double XCoefficient() const;
  double YCoefficient() const;

 private:
  void XCheckOutOfRange(double x_coefficient);
  void YCheckOutOfRange(double y_coefficient);

  static constexpr double kMaximalCoefficient = 3.0;
  static constexpr double kMinimalCoefficient = 0.0;

  double x_coefficient_ = 0.0;
  double y_coefficient_ = 0.0;
};

#endif  // SHIFT_COEFFICIENT_H
