#ifndef SPLASH_SCREEN_SIZE_COMPOSER_H
#define SPLASH_SCREEN_SIZE_COMPOSER_H

#include <QRect>

#include <window_buttons_composer.h>

class QPushButton;
class QLabel;
class QFrame;

class AtmSplashScreen;

class SplashScreenSizeComposer {
 public:
  void InitializeControlButtonsGeometry(const QRect& exit_button,
                                        const QRect& minimize_button,
                                        const QRect& maximaze_button);

  void ComposeFrame(QFrame* frame);
  void ComposeVersionLabel(QLabel* version_label);
  void ComposeWindowControlButtons(QPushButton* exit_button,
                                   QPushButton* minimize_button,
                                   QPushButton* maximize_button);
  void ComposeSplashScreenLabels(QLabel* timedate_label,
                                 QLabel* company_name_label,
                                 QLabel* text_label);

  void ComposeAtmLabel(QLabel* atm_label);

  void SetExtraGeometrySize(int extra_width, int extra_height);

 private:
  void ComputeExtraButtonParameters();

  static QRect kVersionLabel;
  static QRect kCompanyNameLabel;
  static QRect kTimedateLabel;
  static QRect kAtmLabel;
  static QRect kTextLabel;
  static QRect kFrame;

  static const int kAtmLabelFont = 100;
  static const int kSplashScreenWidth = 600;
  static const int kSplashScreenHeight = 400;

  int extra_width_ = 0;
  int extra_height_ = 0;

  WindowButtonsComposer window_button_composer_;
};

#endif  // SPLASH_SCREEN_SIZE_COMPOSER_H
