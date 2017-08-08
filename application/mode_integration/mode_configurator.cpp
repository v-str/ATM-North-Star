#include <mode_configurator.h>

std::string ModeConfigurator::config_file_ = "app_config.txt";

ModeConfigurator::ModeConfigurator() {
  stream_.open(config_file_);
  ReadConfiguration();
  AnalyzeConfigFile();
}

unsigned int ModeConfigurator::GetMode() const { return application_mode_; }

void ModeConfigurator::ReadConfiguration() {
  if (stream_.is_open()) {
    std::getline(stream_, config_string_);
  } else {
    config_string_ = "App congig file was not open...\n";
  }
}

void ModeConfigurator::AnalyzeConfigFile() {
  if (config_string_ == "Mode: cli") {
    application_mode_ = kCli;
  } else if (config_string_ == "Mode: gui") {
    application_mode_ = kGui;
  }
}
