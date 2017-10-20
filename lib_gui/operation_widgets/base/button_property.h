#ifndef BUTTON_PROPERTY_H
#define BUTTON_PROPERTY_H

struct ButtonProperty {
  double StretchX() const;
  double StretchY() const;
  double ShiftX() const;
  double ShiftY() const;

 private:
  static double kButtonStretchX;
  static double kButtonStretchY;
  static double kButtonShiftX;
  static double kButtonShiftY;
};

#endif  // BUTTON_PROPERTY_H
