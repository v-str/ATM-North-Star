#include <splash_screen_size_composer.h>

#include <QFont>
#include <QFontMetrics>
#include <QFrame>
#include <QLabel>

#include <atm_splash_screen.h>

QRect SplashScreenSizeComposer::kVersionLabel(485, 17, 100, 15);
QRect SplashScreenSizeComposer::kCompanyNameLabel(35, 40, 510, 70);
QRect SplashScreenSizeComposer::kTimedateLabel(150, 360, 300, 20);
QRect SplashScreenSizeComposer::kTextLabel(150, 270, 280, 30);
QRect SplashScreenSizeComposer::kFrame(10, 10, 580, 380);

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(kFrame.x(), frame->y(), kFrame.width() + width_increase_,
                     kFrame.height() + height_increase_);
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  version_label->setGeometry(kVersionLabel.x() + width_increase_,
                             kVersionLabel.y(), kVersionLabel.width(),
                             kVersionLabel.height());
}

void SplashScreenSizeComposer::ComposeSplashScreenLabels(
    QLabel* timedate_label, QLabel* company_name_label, QLabel* text_label) {
  timedate_label->setGeometry(kTimedateLabel.x() + width_increase_ / 2,
                              kTimedateLabel.y() + height_increase_,
                              kTimedateLabel.width(), kTimedateLabel.height());

  company_name_label->setGeometry(
      kCompanyNameLabel.x() + width_increase_ / 2, company_name_label->y(),
      company_name_label->width(), company_name_label->height());

  text_label->setGeometry(kTextLabel.x() + width_increase_ / 2,
                          kTextLabel.y() + height_increase_, kTextLabel.width(),
                          kTextLabel.height());
}

void SplashScreenSizeComposer::ComposeAtmLabel(QLabel* atm_label) {
  atm_label_stretcher_.StretchAtmLabel(atm_label, width_increase_,
                                       height_increase_);
}

void SplashScreenSizeComposer::ComputeSizeIncrease(int extra_width,
                                                   int extra_height) {
  width_increase_ = extra_width - kSplashScreenWidth;
  height_increase_ = extra_height - kSplashScreenHeight;
}
