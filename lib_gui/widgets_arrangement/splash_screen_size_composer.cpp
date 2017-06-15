#include <splash_screen_size_composer.h>

#include <QFrame>
#include <QLabel>
#include <QPushButton>

void SplashScreenSizeComposer::RememberInitialGeometry(
    const QRect& splash_screen,
    const QRect& version_label,
    const QRect& company_name_label,
    const QRect& timedate_label,
    const QRect& atm_label,
    const QRect& text_label) {
  splash_screen_ = splash_screen;
  version_label_ = version_label;
  company_name_label_ = company_name_label;
  timedate_label_ = timedate_label;
  atm_label_ = atm_label;
  text_label_ = text_label;
}

void SplashScreenSizeComposer::InitializeFrameGeometry(const QRect& frame) {
  frame_ = frame;
}

void SplashScreenSizeComposer::InitializeControlButtonsGeometry(
    const QRect& exit_button,
    const QRect& minimize_button,
    const QRect& maximaze_button) {
  window_button_composer_.InitializeButtons(exit_button, minimize_button,
                                            maximaze_button);
}

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(frame_.x(), frame->y(), frame_.width() + extra_width_,
                     frame_.height() + extra_height_);
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  version_label->setGeometry(version_label_.x() + extra_width_,
                             version_label_.y(), version_label_.width(),
                             version_label_.height());
}

void SplashScreenSizeComposer::ComposeWindowControlButtons(
    QPushButton* exit_button,
    QPushButton* minimize_button,
    QPushButton* maximize_button) {
  window_button_composer_.InitializeExtraParameters(extra_width_,
                                                    extra_height_);

  window_button_composer_.ComposeWindowButton(exit_button,
                                              ButtonRole::kExitButton);
  window_button_composer_.ComposeWindowButton(minimize_button,
                                              ButtonRole::kMinimizeButton);
  window_button_composer_.ComposeWindowButton(maximize_button,
                                              ButtonRole::kMaximizeButton);
}

void SplashScreenSizeComposer::SetExtraGeometrySize(int extra_width,
                                                    int extra_height) {
  extra_width_ = extra_width - splash_screen_.width();
  extra_height_ = extra_height - splash_screen_.height();
}
