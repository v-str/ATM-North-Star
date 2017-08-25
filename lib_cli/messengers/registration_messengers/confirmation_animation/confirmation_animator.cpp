#include <confirmation_animator.h>

#include <confirmation_frame.h>
#include <console_editor.h>
#include <titler.h>

void ConfirmationAnimator::ShowConfirmationMessage(
    const std::string& login_string) {
  ConfirmationFrame::SetFrame(login_string, "#");

  Titler::WriteTitle("ATM \"NORTH STAR\"");
  DrawConfirmationFrame();
}

void ConfirmationAnimator::DrawConfirmationFrame() {
  for (int loading_percent = 0; loading_percent <= 100; ++loading_percent) {
    Titler::WriteTitle("ATM \"NORTH STAR\"");
    ConfirmationFrame::DrawFrame(loading_percent);
  }
}
