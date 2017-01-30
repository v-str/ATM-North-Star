#include "app_manager.h"
#include "application.h"

int main() {
  AppManager manager;
  manager.SuggestAppMode();

  Application app;
  app.RunProgram(Application::kConsoleMode);
}
