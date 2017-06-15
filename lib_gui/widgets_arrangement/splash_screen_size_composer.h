#ifndef SPLASH_SCREEN_SIZE_COMPOSER_H
#define SPLASH_SCREEN_SIZE_COMPOSER_H

#include <QRect>

#include <window_buttons_composer.h>

class QPushButton;
class QLabel;
class QFrame;

class SplashScreenSizeComposer {
 public:
  void RememberInitialGeometry(const QRect& splash_screen,
                               const QRect& version_label,
                               const QRect& company_name_label,
                               const QRect& timedate_label,
                               const QRect& atm_label,
                               const QRect& text_label);

  void InitializeFrameGeometry(const QRect& frame);

  void InitializeControlButtonsGeometry(const QRect& exit_button,
                                        const QRect& minimize_button,
                                        const QRect& maximaze_button);

  void ComposeFrame(QFrame* frame);
  void ComposeVersionLabel(QLabel* version_label);
  void ComposeWindowControlButtons(QPushButton* exit_button,
                                   QPushButton* minimize_button,
                                   QPushButton* maximize_button);
  void ComposeSplashScreenLabels(QLabel* label);

  void SetExtraGeometrySize(int extra_width, int extra_height);

 private:
  void ComputeExtraButtonParameters();

  QRect splash_screen_;
  QRect version_label_;
  QRect company_name_label_;
  QRect timedate_label_;
  QRect atm_label_;
  QRect text_label_;
  QRect frame_;

  int extra_width_ = 0;
  int extra_height_ = 0;

  WindowButtonsComposer window_button_composer_;
};

#endif  // SPLASH_SCREEN_SIZE_COMPOSER_H
