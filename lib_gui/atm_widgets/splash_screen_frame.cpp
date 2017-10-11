#include <splash_screen_frame.h>

#include <QList>

SplashScreenFrame::SplashScreenFrame(QFrame* parent) : QFrame(parent) {
  PaintWidgets();
}

SplashScreenFrame::~SplashScreenFrame() {}

void SplashScreenFrame::resizeEvent(QResizeEvent* event) {
  composer_.SetFrame(this);
}

void SplashScreenFrame::PaintWidgets() { color_designer_.PaintFrame(this); }
