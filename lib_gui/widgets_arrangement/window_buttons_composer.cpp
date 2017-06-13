#include <window_buttons_composer.h>

void WindowButtonsComposer::InitializeButtons(const QRect& exit_button,
                                              const QRect& minimize_button,
                                              const QRect& maximaze_button) {
  exit_button_ = exit_button;
  minimize_button_ = minimize_button;
  maximaze_button_ = maximaze_button;
}
