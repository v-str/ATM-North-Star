#ifndef WINDOW_BUTTONS_COMPOSER_H
#define WINDOW_BUTTONS_COMPOSER_H

#include <QRect>

class WindowButtonsComposer {
 public:
  void InitializeButtons(const QRect& exit_button,
                         const QRect& minimize_button,
                         const QRect& maximaze_button);

 private:
  QRect exit_button_;
  QRect minimize_button_;
  QRect maximaze_button_;
};

#endif  // WINDOW_BUTTONS_COMPOSER_H
