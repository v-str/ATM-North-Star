#include <process_reporter.h>

std::vector<std::string> ProcessReporter::ProcessReport() const {
  return process_report_;
}

void ProcessReporter::FillReportContainer() {
  process_report_.push_back("Constructing menu list...");
  process_report_.push_back("Add new account to system...");
  process_report_.push_back("Setting up account information...");
  process_report_.push_back("Setting up refill menu...");
  process_report_.push_back("Setting up credit application...");
  process_report_.push_back("Setting up credit manager...");
  process_report_.push_back("Checking actual credit calculation...");
  process_report_.push_back("Update credit interest rate...");
  process_report_.push_back("Update maximum amount of credit...");
  process_report_.push_back("Checking credit parameters...");
  process_report_.push_back("Setting up cash withdrawal service...");
  process_report_.push_back("Setting up withdrawal parameters...");
  process_report_.push_back("Cash dispenser activation...");
  process_report_.push_back("Reports checking...");
  process_report_.push_back("Checking access control service...");
  process_report_.push_back("Checking interaction protocol...");
  process_report_.push_back("Checking video controller");
  process_report_.push_back("Internal video system activation...");
  process_report_.push_back("External video system activation...");
  process_report_.push_back("WebATM activation...");
  process_report_.push_back("X.25 protocol activation...");
  process_report_.push_back("X.25-1 protocol activation...");
  process_report_.push_back("Detect standard link connection... ");
  process_report_.push_back("Wi-fi adapter activation...");
}
