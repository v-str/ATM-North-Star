#ifndef SHIFTER_H
#define SHIFTER_H

#include <conversion_factor.h>

class Shifter {
 public:
  Shifter();
  Shifter(const ConversionFactor& shift_factor);

 private:
  ConversionFactor shift_factor_;
};

#endif  // SHIFTER_H
