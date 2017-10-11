﻿#include <atm_label_stretcher.h>

#include <QFontMetrics>
#include <QLabel>

#include <splash_screen_geometry.h>

void AtmLabelStretcher::StretchAtmLabel(QLabel* atm_label, int width_increase,
                                        int height_increase) {
  width_increase_ = width_increase;
  height_increase_ = height_increase;

  ComputeFontSize();
  FitFrameByFontSize(atm_label);
  PerformStretching(atm_label);
}

void AtmLabelStretcher::ComputeFontSize() {
  int font_growth = (width_increase_ - height_increase_) / 12;
  font_pointsize_ = kInitFontSize + font_growth;

  if (font_pointsize_ < kInitFontSize) {
    font_pointsize_ = kInitFontSize;
  }

  if (font_pointsize_ > kFontSizeLimit) {
    font_pointsize_ = kFontSizeLimit;
  }
}

void AtmLabelStretcher::FitFrameByFontSize(const QLabel* atm_label) {
  font_ = atm_label->font();
  QFontMetrics font_metrics(atm_label->font());

  font_height_ = font_metrics.capHeight();
  int frame_height =
      SplashScreenGeometry::AtmLabel().height() + height_increase_;

  if (font_height_ > frame_height) {
    frame_height = font_height_ + 30;
  }
}

void AtmLabelStretcher::PerformStretching(QLabel* atm_label) {
  font_.setPointSize(font_pointsize_);
  atm_label->setFont(font_);

  atm_label->setGeometry(
      SplashScreenGeometry::AtmLabel().x(),
      SplashScreenGeometry::AtmLabel().y(),
      SplashScreenGeometry::AtmLabel().width() + width_increase_,
      SplashScreenGeometry::AtmLabel().height() + height_increase_);
}
