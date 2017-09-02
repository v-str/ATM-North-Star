#include <confirmation_animator.h>

#include <confirmation_frame.h>
#include <console_editor.h>
#include <titler.h>

std::vector<std::string> ConfirmationAnimator::processes_report_;
std::string ConfirmationAnimator::kFrameSymbol;

void ConfirmationAnimator::ShowAnimation() { DrawConfirmationFrame(); }

void ConfirmationAnimator::SetLoginForAnimation(
    const std::string& login_string) {
  kFrameSymbol = login_string.at(0);

  ConfirmationFrame::SetFrame(login_string, kFrameSymbol);
}

void ConfirmationAnimator::SetProcessesReport(
    const std::vector<std::string>& processes_report) {
  processes_report_ = processes_report;
}

void ConfirmationAnimator::DrawConfirmationFrame() {
  for (int loading_percent = 0; loading_percent <= 100; ++loading_percent) {
    UpdateFrame(loading_percent);
  }
  Titler::WriteEnterMessage();
}

void ConfirmationAnimator::UpdateFrame(int loading_percent) {
  ConsoleEditor::ClearScreen();

  Titler::WriteLogoTitle("ATM \"NORTH STAR\"");

  ConfirmationFrame::DrawFrame(loading_percent);
  ConsoleEditor::Sleep(std::rand() % kSleepDelay);
}
