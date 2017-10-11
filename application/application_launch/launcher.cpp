#include <launcher.h>

#include <iostream>

#include <QApplication>

#include <console_initial_presenter.h>
#include <main_widget_presenter.h>

void Launcher::LaunchConsoleMode() {
  console_initial_presenter_ = new ConsoleInitialPresenter;
  console_initial_presenter_->RunApplication();
  delete console_initial_presenter_;
}

void Launcher::LaunchGuiMode(int argc, char* argv[]) {
  QApplication application(argc, argv);
  Q_INIT_RESOURCE(atm_resources);

  graphical_initial_presenter_ = new MainWidgetPresenter;
  graphical_initial_presenter_->RunApplication();

  application.exec();
  delete graphical_initial_presenter_;
}

void Launcher::DisplayErrorReport() const {
  std::cout
      << "Error while reading configuration file \"app_config.txt\"\n"
         "Configuration file was not created or contain incorrect data...\n\n\n"
         "For successful program launching you must to create a "
         "\"app_config.txt\" file\n"
         "and put it near the executed file.\n"
         "In configuration file you must write which mode of app you want to "
         "use.\n"
         "If you want to run app in console mode, write \"Mode: cli\"\n"
         "Or if you want to run app in graphical mode, write \"Mode: gui\"\n";
}
