#include <atm_main_widget.h>
#include <ui_atm_main_widget.h>

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
#include <painter.h>
#include <splash_screen_frame.h>
#include <time_label.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);

  setWindowTitle("ATM");

  SetInitialSettings();
  SetInitialMainWidgetProperties();
  SetConnections();
}

AtmMainWidget::~AtmMainWidget() {
  delete ui;
  delete time_label_;
  delete date_label_;
}

void AtmMainWidget::SetCompanyName(const QString& company_name) {
  splash_screen_->SetCompanyName(company_name);
}

QFrame* AtmMainWidget::GetMainFrame() const { return ui->main_frame; }

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
  PaintWidgets();
  SetImages();

  setMinimumSize(kAppWidth, kAppHeight);
  initial_menu_->close();
}

void AtmMainWidget::InitializeObjects() {
  splash_screen_ = new SplashScreenFrame(ui->main_frame);
  initial_menu_ = new GraphicalInitialMenu(ui->main_frame);
  time_label_ = new TimeLabel(static_cast<QLabel*>(ui->main_frame));
  date_label_ = new DateLabel(static_cast<QLabel*>(ui->main_frame));
}

void AtmMainWidget::PaintWidgets() {
  QList<QFrame*> frame_list = {ui->main_frame};
  QList<QLabel*> label_list = {time_label_, date_label_};

  color_designer_.PaintWidgetSet(&frame_list);
  color_designer_.PaintWidgetSet(&label_list);
  color_designer_.SetBackground(this);
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
  main_widget_composer_.SetMainFrame(ui->main_frame);
  main_widget_composer_.SetTimeAndDate(time_label_, date_label_);
  main_widget_composer_.ComposeMenu(initial_menu_);
  main_widget_composer_.ComposeSplashScreen(splash_screen_);
}

void AtmMainWidget::ComputeDeltaSize() {
  delta_width_ = width() - Geometry::InitialScreenWidth();
  delta_height_ = height() - Geometry::InitialScreenHeight();
  main_widget_composer_.SetDeltaSize(DeltaSize(delta_width_, delta_height_));
  initial_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
}
