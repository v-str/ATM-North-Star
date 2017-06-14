#ifndef WINDOW_BUTTONS_COMPOSER_H
#define WINDOW_BUTTONS_COMPOSER_H

#include <QRect>

class QPushButton;

class WindowButtonsComposer {
 public:
  void InitializeButtons(const QRect& exit_button,
                         const QRect& minimize_button,
                         const QRect& maximize_button);

  void ResizeExitButton(QPushButton* exit_button);
  void ResizeMinimizeButton(QPushButton* minimize_button);
  void ResizeMaximizeButton(QPushButton* maximize_button);

  void InitializeExtraParameters(int extra_width, int extra_height);

 private:
  void ComputeExtraButtonSize();

  QRect exit_button_;
  QRect minimize_button_;
  QRect maximize_button_;

  int extra_width_ = 0;
  int extra_height_ = 0;

  int growth_width_criterion_ = 0;
  int growth_height_criterion_ = 0;
};

#endif  // WINDOW_BUTTONS_COMPOSER_H
