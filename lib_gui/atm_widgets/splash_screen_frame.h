#ifndef SPLASH_SCREEN_FRAME_H
#define SPLASH_SCREEN_FRAME_H

#include <base_atm_frame.h>

#include <atm_color_designer.h>

class SplashScreenFrame : public BaseAtmFrame {
  Q_OBJECT

 public:
  explicit SplashScreenFrame(QWidget* parent = nullptr);
  ~SplashScreenFrame();

 private:
  void SetInitialSettings();

  GeometryComposer composer_;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;

  static const int kHalfASecond = 500;
};

#endif  // SPLASH_SCREEN_FRAME_H
