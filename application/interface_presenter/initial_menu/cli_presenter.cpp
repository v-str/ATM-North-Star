#include <cli_presenter.h>

CLIPresenter::CLIPresenter() {
  console_viewer_ = std::unique_ptr<ConsoleViewer>(new ConsoleViewer);
}

void CLIPresenter::RunApplication() {
  console_viewer_->RunView();
  RunSubMenu(console_viewer_->GetSubMenu());
}

void CLIPresenter::RunSubMenu(int sub_menu) {
  if (sub_menu == ConsoleViewer::kLoginMenu) {
    console_viewer_->RunLoginMenu();
  }
  if (sub_menu == ConsoleViewer::kRegistrationMenu) {
    // console_viewer_->RunRegistrationMenu();
  }
  if (sub_menu == ConsoleViewer::kDemoMenu) {
    // console_viewer_->RunDemoMenu();
  }
  if (sub_menu == ConsoleViewer::kExit) {
    // console_viewer_->DisplayFarewellMessage();
  }
}
