#include "app_manager.h"
#include "application.h"

int main() {
  AppManager::SuggestAppMode();

  Application app;
  app.RunProgram(AppManager::GetMode());
}
