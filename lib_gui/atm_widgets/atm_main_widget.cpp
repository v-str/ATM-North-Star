#include <atm_main_widget.h>

#include <QCursor>
#include <QIcon>
#include <QLabel>
#include <QList>
#include <QPaintEvent>
#include <QPixmap>
#include <QResizeEvent>
#include <QTimer>

#include <date_label.h>
#include <delta_size.h>
#include <geometry.h>
#include <graphical_initial_menu.h>
#include <initial_property_installer.h>
#include <main_frame.h>
#include <splash_screen_frame.h>
#include <time_label.h>

AtmMainWidget::AtmMainWidget(QWidget* parent) : QMainWindow(parent) {
  setWindowTitle("ATM");

  SetInitialSettings();
  SetInitialMainWidgetProperties();
  SetConnections();
}

AtmMainWidget::~AtmMainWidget() {}

void AtmMainWidget::SetCompanyName(const QString& company_name) {
  splash_screen_->SetCompanyName(company_name);
}

QFrame* AtmMainWidget::GetMainFrame() const { return main_frame_; }

void AtmMainWidget::ProcessLoginButtonClick() {
  emit LoginButtonClicked();
  emit MainWidgetGeometryChanged(DeltaSize(delta_width_, delta_height_));
}

void AtmMainWidget::ProcessRegistrationButtonClick() {
  emit RegistrationButtonClicked();
  emit MainWidgetGeometryChanged(DeltaSize(delta_width_, delta_height_));
}

void AtmMainWidget::ProcessInitialMenuOpening() { emit ShowInitialMenu(); }

void AtmMainWidget::resizeEvent(QResizeEvent*) {
  ComputeDeltaSize();
  ComposeWidgets();

  emit MainWidgetGeometryChanged(DeltaSize(delta_width_, delta_height_));
}

void AtmMainWidget::SetInitialSettings() {
  InitializeObjects();
  SetImages();

  setMinimumSize(kAppWidth, kAppHeight);
  initial_menu_->close();
}

void AtmMainWidget::InitializeObjects() {
  main_frame_ = new MainFrame(this);
  splash_screen_ = new SplashScreenFrame(main_frame_);
  initial_menu_ = new GraphicalInitialMenu(main_frame_);
}

void AtmMainWidget::SetImages() {
  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);
  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmMainWidget::SetInitialMainWidgetProperties() {
  InitialPropertyInstaller::SetInitialProperties(
      this, kAppWidth, kAppHeight, InitialPropertyInstaller::kResize);
}

void AtmMainWidget::SetConnections() {
  connect(initial_menu_, SIGNAL(LoginButtonClicked()),
          SLOT(ProcessLoginButtonClick()));
  connect(initial_menu_, SIGNAL(RegistrationButtonClicked()),
          SLOT(ProcessRegistrationButtonClick()));
  connect(this, SIGNAL(ShowInitialMenu()), initial_menu_, SLOT(Show()));
}

void AtmMainWidget::ComposeWidgets() {
  main_widget_composer_.ComposeMainFrame(main_frame_);
  main_widget_composer_.ComposeMenu(initial_menu_);
  main_widget_composer_.ComposeMenu(splash_screen_);
}

void AtmMainWidget::ComputeDeltaSize() {
  delta_width_ = width() - Geometry::InitialScreenWidth();
  delta_height_ = height() - Geometry::InitialScreenHeight();
  main_widget_composer_.SetDeltaSize(DeltaSize(delta_width_, delta_height_));
  initial_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
}
