#include <main_widget_presenter.h>

#include <atm_main_widget.h>
#include <graphical_login_menu.h>
#include <graphical_registration_menu.h>

MainWidgetPresenter::MainWidgetPresenter(QObject* parent)
    : QObject(parent), atm_main_widget_(new AtmMainWidget) {
  atm_main_widget_->SetCompanyName("North Star");

  CreateLoginMenu();
  CreateRegistrationMenu();

  ConnectLoginMenu();
  ConnectRegistrationMenu();
}

MainWidgetPresenter::~MainWidgetPresenter() { delete atm_main_widget_; }

void MainWidgetPresenter::RunApplication() { atm_main_widget_->showNormal(); }

void MainWidgetPresenter::SetWidgetGeometry(const QRect& initial_position) {
  main_widget_position_ = initial_position;
}

void MainWidgetPresenter::SetMaximized(bool is_maximized) {
  is_maximized_ = is_maximized;
}

void MainWidgetPresenter::CreateLoginMenu() {
  login_menu_ = new GraphicalLoginMenu(atm_main_widget_->GetMainFrame());
  login_menu_->close();
}

void MainWidgetPresenter::CreateRegistrationMenu() {
  registration_menu_ =
      new GraphicalRegistrationMenu(atm_main_widget_->GetMainFrame());
  registration_menu_->close();
}

void MainWidgetPresenter::ConnectLoginMenu() {
  connect(atm_main_widget_, SIGNAL(MainWidgetGeometryChanged(DeltaSize)),
          login_menu_, SLOT(ChangeLoginMenuGeometry(DeltaSize)));
  connect(atm_main_widget_, SIGNAL(LoginButtonClicked()), login_menu_,
          SLOT(Show()));
  connect(login_menu_, SIGNAL(BackButtonClicked()), atm_main_widget_,
          SLOT(ProcessInitialMenuOpening()));
}

void MainWidgetPresenter::ConnectRegistrationMenu() {
  connect(atm_main_widget_, SIGNAL(MainWidgetGeometryChanged(DeltaSize)),
          registration_menu_, SLOT(ChangeRegistrationMenuGeometry(DeltaSize)));
  connect(atm_main_widget_, SIGNAL(RegistrationButtonClicked()),
          registration_menu_, SLOT(Show()));
  connect(registration_menu_, SIGNAL(BackButtonClicked()), atm_main_widget_,
          SLOT(ProcessInitialMenuOpening()));
}
