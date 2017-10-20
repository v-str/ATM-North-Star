#ifndef FRAME_PROPERTY_H
#define FRAME_PROPERTY_H

struct FrameProperty {
  static double StretchX();
  static double StretchY();

 private:
  static constexpr double kFrameStretchX = 1.0;
  static constexpr double kFrameStretchY = 1.0;
};

#endif  // FRAME_PROPERTY_H
