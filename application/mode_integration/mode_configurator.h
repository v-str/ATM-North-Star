#ifndef MODE_CONFIGURATOR_H
#define MODE_CONFIGURATOR_H

#include <fstream>
#include <string>

class ModeConfigurator {
 public:
  enum kAppMode { kError, kCli, kGui };

  ModeConfigurator();

  int GetMode() const;

 private:
  void ReadConfiguration();
  void AnalyzeConfigFile();

  static std::string config_file_;

  std::fstream stream_;
  std::string config_string_;

  int application_mode_ = kError;
};

#endif  // MODE_CONFIGURATOR_H
