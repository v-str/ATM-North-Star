#include <splash_screen_size_composer.h>

#include <QFont>
#include <QFontMetrics>
#include <QFrame>
#include <QLabel>
#include <QPushButton>

#include <atm_splash_screen.h>

void SplashScreenSizeComposer::RememberInitialGeometry(
    const QRect& version_label,
    const QRect& company_name_label,
    const QRect& timedate_label,
    const QRect& atm_label,
    const QRect& text_label) {
  kVersionLabel = version_label;
  kCompanyNameLabel = company_name_label;
  kTimedateLabel = timedate_label;
  kAtmLabel = atm_label;
  kTextLabel = text_label;
}

void SplashScreenSizeComposer::InitializeFrameGeometry(const QRect& frame) {
  kFrame = frame;
}

void SplashScreenSizeComposer::InitializeControlButtonsGeometry(
    const QRect& exit_button,
    const QRect& minimize_button,
    const QRect& maximaze_button) {
  window_button_composer_.InitializeButtons(exit_button, minimize_button,
                                            maximaze_button);
}

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(kFrame.x(), frame->y(), kFrame.width() + extra_width_,
                     kFrame.height() + extra_height_);
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  version_label->setGeometry(kVersionLabel.x() + extra_width_,
                             kVersionLabel.y(), kVersionLabel.width(),
                             kVersionLabel.height());
}

void SplashScreenSizeComposer::ComposeWindowControlButtons(
    QPushButton* exit_button,
    QPushButton* minimize_button,
    QPushButton* maximize_button) {
  window_button_composer_.AssignExtraParameters(extra_width_, extra_height_);

  window_button_composer_.ComposeWindowButton(exit_button,
                                              ButtonRole::kExitButton);
  window_button_composer_.ComposeWindowButton(minimize_button,
                                              ButtonRole::kMinimizeButton);
  window_button_composer_.ComposeWindowButton(maximize_button,
                                              ButtonRole::kMaximizeButton);
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
  atm_label->setGeometry(kAtmLabel.x(), kAtmLabel.y(),
                         kAtmLabel.width() + extra_width_,
                         kAtmLabel.height() + extra_height_);

  int font_size = kAtmLabelFont;

  int font_criterion = 0;

  font_criterion = (extra_width_ - extra_height_) / 3;

  font_size += font_criterion;

  if (font_size < kAtmLabelFont) font_size = kAtmLabelFont;
  if (font_size > 170) font_size = 170;

  QFont font("FreeSans", font_size, QFont::Bold);
  QFontMetrics font_metrics(font);

  int font_height = font_metrics.capHeight();

  if (font_height > (kAtmLabel.height() + extra_height_)) {
    atm_label->setGeometry(kAtmLabel.x(), kAtmLabel.y(),
                           kAtmLabel.width() + extra_width_, font_height);
  }

  atm_label->setFont(QFont("FreeSans", font_size, QFont::Bold));
}

void SplashScreenSizeComposer::SetExtraGeometrySize(int extra_width,
                                                    int extra_height) {
  extra_width_ = extra_width - kSplashScreenWidth;
  extra_height_ = extra_height - kSplashScreenHeight;
}
