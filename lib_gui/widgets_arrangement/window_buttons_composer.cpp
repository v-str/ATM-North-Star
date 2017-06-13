#include <window_buttons_composer.h>

#include <QtCore/qmath.h>
#include <QPushButton>

void WindowButtonsComposer::InitializeButtons(const QRect& exit_button,
                                              const QRect& minimize_button,
                                              const QRect& maximize_button) {
  exit_button_ = exit_button;
  minimize_button_ = minimize_button;
  maximize_button_ = maximize_button;
}

void WindowButtonsComposer::ResizeExitButton(QPushButton* exit_button) {
  ComputeExtraButtonSize();

  exit_button->setGeometry(exit_button_.x(), exit_button_.y(),
                           exit_button_.width() + growth_width_criterion_,
                           exit_button_.height() + growth_height_criterion_);
}

void WindowButtonsComposer::ResizeMinimizeButton(QPushButton* minimize_button) {
  ComputeExtraButtonSize();

  minimize_button->setGeometry(
      minimize_button_.x() + growth_width_criterion_, minimize_button_.y(),
      minimize_button_.width() + growth_width_criterion_,
      minimize_button_.height() + growth_height_criterion_);
}

void WindowButtonsComposer::ResizeMaximizeButton(QPushButton* maximize_button) {
  ComputeExtraButtonSize();

  maximize_button->setGeometry(
      maximize_button_.x() + growth_width_criterion_ * 2, maximize_button_.y(),
      maximize_button_.width() + growth_width_criterion_,
      maximize_button_.height() + growth_height_criterion_);
}

void WindowButtonsComposer::SetExtraWidthSize(int extra_width) {
  extra_width_ = extra_width;
}

void WindowButtonsComposer::SetExtraHeightSize(int extra_height) {
  extra_height_ = extra_height;
}

void WindowButtonsComposer::ComputeExtraButtonSize() {
  int extra_width = extra_width_;
  int extra_height = extra_height_;

  growth_width_criterion_ = qCeil(extra_width / 100);
  growth_height_criterion_ = qCeil(extra_height / 100);
}
