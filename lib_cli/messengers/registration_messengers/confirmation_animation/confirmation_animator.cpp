#include <confirmation_animator.h>

#include <confirmation_frame.h>
#include <console_editor.h>
#include <titler.h>

std::vector<std::string> ConfirmationAnimator::processes_report_;
std::string ConfirmationAnimator::kFrameSymbol;

void ConfirmationAnimator::ShowAnimation() { DrawConfirmationFrame(); }

void ConfirmationAnimator::SeFrameBasedOnLoginSymbols(
    const std::string& login_string) {
  kFrameSymbol = login_string.at(0);

  ConfirmationFrame::SetFrame(login_string, kFrameSymbol);
}

void ConfirmationAnimator::SetProcessesReport(
    const std::vector<std::string>& processes_report) {
  processes_report_ = processes_report;
}

void ConfirmationAnimator::DrawConfirmationFrame() {
  int process_index = 0;

  for (int loading_percent = 0; loading_percent <= 100; ++loading_percent) {
    if (loading_percent % 5 == 0) {
      process_index++;
    }

    UpdateFrame(loading_percent, processes_report_.at(process_index));
  }

  ConsoleEditor::ClearScreen();
  Titler::WriteLogoTitle("ATM \"NORTH STAR\"");
  ConfirmationFrame::DrawFrame(100, "Account created: ", "Ready to work");

  Titler::WriteEnterMessage();
}

void ConfirmationAnimator::UpdateFrame(int loading_percent,
                                       const std::string& process_report) {
  ConsoleEditor::ClearScreen();

  Titler::WriteLogoTitle("ATM \"NORTH STAR\"");

  ConfirmationFrame::DrawFrame(loading_percent, "Creating account:",
                               process_report);
  ConsoleEditor::Sleep(std::rand() % kSleepDelay);
}
