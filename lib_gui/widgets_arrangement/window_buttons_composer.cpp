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

void WindowButtonsComposer::ResizeWindowButton(QPushButton* window_button,
                                               const ButtonRole& button_role) {
  QRect new_geometry(0, 0, 0, 0);
  int x_offset = x_offset_;

  switch (button_role) {
    case ButtonRole::kExitButton:
      new_geometry = exit_button_;
      x_offset *= 0;
      break;
    case ButtonRole::kMinimizeButton:
      new_geometry = minimize_button_;
      x_offset *= 1;
      break;
    case ButtonRole::kMaximizeButton:
      new_geometry = maximize_button_;
      x_offset *= 2;
      break;
    default:
      break;
  }

  window_button->setGeometry(new_geometry.x() + x_offset, new_geometry.y(),
                             new_geometry.width() + growth_width_criterion_,
                             new_geometry.height() + growth_height_criterion_);
}

void WindowButtonsComposer::InitializeExtraParameters(int extra_width,
                                                      int extra_height) {
  extra_width_ = extra_width;
  extra_height_ = extra_height;

  ComputeExtraButtonSize();
}

void WindowButtonsComposer::ComputeExtraButtonSize() {
  int extra_width = extra_width_;
  int extra_height = extra_height_;

  growth_width_criterion_ = qCeil(extra_width / 50);
  growth_height_criterion_ = qCeil(extra_height / 50);

  x_offset_ = growth_width_criterion_;
}
