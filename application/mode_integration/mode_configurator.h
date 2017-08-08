#ifndef MODE_CONFIGURATOR_H
#define MODE_CONFIGURATOR_H

#include <fstream>
#include <string>

class ModeConfigurator {
 public:
  enum kAppMode { kConsoleMode, kGraphicalMode };

  ModeConfigurator();

  int GetMode() const;

 private:
  void ReadConfiguration();
  void AnalyzeConfigFile();

  static std::string config_file_;

  std::fstream stream_;
  std::string config_string_;

  int application_mode_ = -1;
};

#endif  // MODE_CONFIGURATOR_H
