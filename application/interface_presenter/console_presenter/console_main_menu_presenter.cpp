#include <console_main_menu_presenter.h>

void ConsoleMainMenuPresenter::RunMainMenu() {
  main_menu_.RunMainMenu();
  if (main_menu_.UserWantAccountSubMenu()) {
    // run account submenu class object
  }
}
