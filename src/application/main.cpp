#include "app_manager.h"
#include "application.h"

int main() {
  AppManager::SuggestMode();

  Application app;
  app.RunProgram(AppManager::GetMode());
}
