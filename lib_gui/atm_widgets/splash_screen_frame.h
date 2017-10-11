#ifndef SPLASH_SCREEN_FRAME_H
#define SPLASH_SCREEN_FRAME_H

#include <QFrame>

#include <atm_color_designer.h>
#include <splash_screen_composer.h>

class SplashScreenFrame : public QFrame {
  Q_OBJECT

 public:
  explicit SplashScreenFrame(QFrame* parent = nullptr);
  ~SplashScreenFrame();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void PaintWidgets();

  void ProcessEnterKey();

  SplashScreenComposer composer_;
  AtmColorDesigner color_designer_;
};

#endif  // SPLASH_SCREEN_FRAME_H
