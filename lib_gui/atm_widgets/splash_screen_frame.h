#ifndef SPLASH_SCREEN_FRAME_H
#define SPLASH_SCREEN_FRAME_H

#include <QFrame>

class SplashScreenFrame : public QFrame {
  Q_OBJECT

 public:
  explicit SplashScreenFrame(QFrame* parent = nullptr);
  ~SplashScreenFrame();

 private:
};

#endif  // SPLASH_SCREEN_FRAME_H
