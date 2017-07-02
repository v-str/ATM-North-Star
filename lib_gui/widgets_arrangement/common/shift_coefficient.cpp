#include <shift_coefficient.h>

ShiftCoefficient::ShiftCoefficient(double x_coefficient, double y_coefficient)
    : x_coefficient_(x_coefficient), y_coefficient_(y_coefficient) {}

double ShiftCoefficient::XCoefficient() const { return x_coefficient_; }

double ShiftCoefficient::YCoefficient() const { return y_coefficient_; }
