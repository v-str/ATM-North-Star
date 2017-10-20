#ifndef BUTTON_PROPERTY_H
#define BUTTON_PROPERTY_H

struct ButtonProperty {
  static double StretchX();
  static double StretchY();
  static double ShiftX();
  static double ShiftY();

 private:
  static constexpr double kButtonStretchX = 0.7;
  static constexpr double kButtonStretchY = 0.3;
  static constexpr double kButtonShiftX = 0.0;
  static constexpr double kButtonShiftY = 1.0;
};

#endif  // BUTTON_PROPERTY_H
