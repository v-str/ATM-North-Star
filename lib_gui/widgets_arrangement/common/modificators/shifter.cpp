#include <shifter.h>

Shifter::Shifter() {}

Shifter::Shifter(const ConversionFactor& shift_factor) {
  shift_factor_ = shift_factor;
}
