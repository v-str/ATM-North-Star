#include <splash_screen_size_composer.h>

#include <QFont>
#include <QFontMetrics>
#include <QFrame>
#include <QLabel>

#include <atm_splash_screen.h>

QRect SplashScreenSizeComposer::kVersionLabel(520, 17, 60, 15);
QRect SplashScreenSizeComposer::kCompanyNameLabel(35, 40, 510, 70);
QRect SplashScreenSizeComposer::kTimedateLabel(160, 360, 280, 20);
QRect SplashScreenSizeComposer::kAtmLabel(140, 100, 300, 150);
QRect SplashScreenSizeComposer::kTextLabel(170, 270, 240, 30);
QRect SplashScreenSizeComposer::kFrame(10, 10, 580, 380);

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(kFrame.x(), frame->y(), kFrame.width() + extra_width_,
                     kFrame.height() + extra_height_);
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  version_label->setGeometry(kVersionLabel.x() + extra_width_,
                             kVersionLabel.y(), kVersionLabel.width(),
                             kVersionLabel.height());
}

void SplashScreenSizeComposer::ComposeSplashScreenLabels(
    QLabel* timedate_label, QLabel* company_name_label, QLabel* text_label) {
  timedate_label->setGeometry(kTimedateLabel.x() + extra_width_ / 2,
                              kTimedateLabel.y() + extra_height_,
                              kTimedateLabel.width(), kTimedateLabel.height());

  company_name_label->setGeometry(
      kCompanyNameLabel.x() + extra_width_ / 2, company_name_label->y(),
      company_name_label->width(), company_name_label->height());

  text_label->setGeometry(kTextLabel.x() + extra_width_ / 2,
                          kTextLabel.y() + extra_height_, kTextLabel.width(),
                          kTextLabel.height());
}

void SplashScreenSizeComposer::ComposeAtmLabel(QLabel* atm_label) {
  int font_criterion = (extra_width_ - extra_height_) / 3;
  int font_size = kAtmLabelFontSize;

  font_size += font_criterion;

  if (font_size < kAtmLabelFontSize) font_size = kAtmLabelFontSize;
  if (font_size > 170) font_size = 170;

  QFont font(atm_label->font());
  QFontMetrics font_metrics(font);

  int font_height = font_metrics.capHeight();
  int frame_height = kAtmLabel.height() + extra_height_;

  if (font_height > frame_height) {
    frame_height = font_height + 10;
  }
  font.setPointSize(font_size);
  atm_label->setFont(font);
  atm_label->setGeometry(kAtmLabel.x(), kAtmLabel.y(),
                         kAtmLabel.width() + extra_width_, frame_height);
}

void SplashScreenSizeComposer::SetExtraGeometrySize(int extra_width,
                                                    int extra_height) {
  extra_width_ = extra_width - kSplashScreenWidth;
  extra_height_ = extra_height - kSplashScreenHeight;
}
