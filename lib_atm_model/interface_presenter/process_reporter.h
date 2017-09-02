#ifndef PROCESS_REPORTER_H
#define PROCESS_REPORTER_H

#include <string>
#include <vector>

class ProcessReporter {
 public:
  ProcessReporter();

  std::vector<std::string> ProcessReport() const;

 private:
  void FillReportContainer();

  std::vector<std::string> process_report_;
};

#endif  // PROCESS_REPORTER_H
