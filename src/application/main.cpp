#include "app_manager.h"
#include "application.h"

int main() {
  AppManager app_manager;
  app_manager.SuggestMode();

  Application app;
  app.RunProgram(app_manager.GetMode());
}
