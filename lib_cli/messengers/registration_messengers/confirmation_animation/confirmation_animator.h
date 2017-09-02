#ifndef CONFIRMATION_ANIMATOR_H
#define CONFIRMATION_ANIMATOR_H

#include <string>
#include <vector>

class ConfirmationAnimator {
 public:
  static void ShowAnimation();

  static void SeFrameBasedOnLoginSymbols(const std::string& login_string);
  static void SetProcessesReport(
      const std::vector<std::string>& processes_report);

 private:
  static void DrawConfirmationFrame();
  static void UpdateFrame(int loading_percent,
                          const std::string& process_report);

  static void DrawFinalFrame();

  static std::vector<std::string> processes_report_;

  static std::string kFrameSymbol;

  static const int kSleepDelay = 21;
};

#endif  // CONFIRMATION_ANIMATOR_H
