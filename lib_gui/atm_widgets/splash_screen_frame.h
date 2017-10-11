#ifndef SPLASH_SCREEN_FRAME_H
#define SPLASH_SCREEN_FRAME_H

#include <base_atm_frame.h>

#include <atm_color_designer.h>
#include <splash_screen_composer.h>

class SplashScreenFrame : public BaseAtmFrame {
  Q_OBJECT

 public:
  explicit SplashScreenFrame(QWidget* parent = nullptr);
  ~SplashScreenFrame();
};

#endif  // SPLASH_SCREEN_FRAME_H
