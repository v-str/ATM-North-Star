#ifndef SPLASH_SCREEN_SIZE_COMPOSER_H
#define SPLASH_SCREEN_SIZE_COMPOSER_H

#include <QRect>

#include <atm_label_stretcher.h>

class QPushButton;
class QLabel;
class QFrame;

class AtmSplashScreen;

class SplashScreenSizeComposer {
 public:
  void ComposeFrame(QFrame* frame);
  void ComposeVersionLabel(QLabel* version_label);
  void ComposeSplashScreenLabels(QLabel* timedate_label,
                                 QLabel* company_name_label,
                                 QLabel* text_label);

  void ComposeAtmLabel(QLabel* atm_label);

  void ComputeSizeIncrease(int extra_width, int extra_height);

 private:
  static QRect kVersionLabel;
  static QRect kCompanyNameLabel;
  static QRect kTimedateLabel;
  static QRect kTextLabel;
  static QRect kFrame;

  static const int kAtmLabelFontSize = 100;
  static const int kSplashScreenWidth = 600;
  static const int kSplashScreenHeight = 400;

  int width_increase_ = 0;
  int height_increase_ = 0;

  AtmLabelStretcher atm_label_stretcher_;
};

#endif  // SPLASH_SCREEN_SIZE_COMPOSER_H
