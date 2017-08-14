#include <cli_presenter.h>

CLIPresenter::CLIPresenter() {
  initial_menu_ = std::unique_ptr<ConsoleInitialMenu>(new ConsoleInitialMenu);
}

void CLIPresenter::RunApplication() {
  initial_menu_->RunInitialMenu();
  RunSubMenu(initial_menu_->GetSubMenu());
}

void CLIPresenter::RunSubMenu(int sub_menu) {
  if (sub_menu == ConsoleInitialMenu::kLoginMenu) {
    initial_menu_->RunLoginMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kRegistrationMenu) {
    // console_viewer_->RunRegistrationMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kDemoMenu) {
    initial_menu_->RunDescriptionMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kExit) {
    initial_menu_->DisplayFarewellMessage();
  }
}
