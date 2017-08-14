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

#include <description_menu_geometry.h>
#include <geometry.h>
#include <graphical_description_menu.h>
#include <graphical_initial_menu.h>
#include <graphical_login_menu.h>
#include <graphical_registration_menu.h>
#include <initial_frame_geometry.h>
#include <initial_property_installer.h>
#include <main_widget_geometry.h>
#include <painter.h>
#include <side.h>
#include <timedate_changer.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);

  setWindowTitle("ATM");

  SetInitialSettings();

  SetWidgetProperties();
  PaintWidgets();
  SetConnections();
  RunTimers();
}

AtmMainWidget::~AtmMainWidget() {
  delete ui;
  delete time_timer_;
}

void AtmMainWidget::SetImages() {
  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);

  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmMainWidget::MaximizeButtonClicked(bool) {
  if (!isFullScreen()) {
    showFullScreen();
  } else {
    showNormal();
  }
}

void AtmMainWidget::TickTime() { TimeDateChanger::ChangeTime(ui->time_label); }

void AtmMainWidget::resizeEvent(QResizeEvent*) {
  ComputeExtraSize();
  SetFrameArrangement();
  SetTimeLabelArrangement();
}

void AtmMainWidget::SetConnections() {
  connect(ui->maximize_button, SIGNAL(clicked(bool)),
          SLOT(MaximizeButtonClicked(bool)));
  connect(time_timer_, SIGNAL(timeout()), SLOT(TickTime()));

  connect(initial_menu_, SIGNAL(DemoButtonClicked()), description_menu_,
          SLOT(Show()));
  connect(initial_menu_, SIGNAL(RegistrationButtonClicked()),
          registration_menu_, SLOT(Show()));
  connect(initial_menu_, SIGNAL(LoginButtonClicked()), login_menu_,
          SLOT(Show()));

  connect(description_menu_, SIGNAL(BackButtonClicked()), initial_menu_,
          SLOT(Show()));
  connect(registration_menu_, SIGNAL(BackButtonClicked()), initial_menu_,
          SLOT(Show()));
  connect(login_menu_, SIGNAL(BackButtonClicked()), initial_menu_,
          SLOT(Show()));
}

void AtmMainWidget::SetInitialSettings() {
  InitializeObject();
  PaintWidgets();
  SetBackground();
  SetImages();

  description_menu_->close();
  registration_menu_->close();
  login_menu_->close();
}

void AtmMainWidget::SetBackground() { color_designer_.SetBackground(this); }

void AtmMainWidget::SetWidgetProperties() {
  setMinimumSize(kAppWidth, kAppHeight);
  InitialPropertyInstaller::SetInitialProperties(
      this, kAppWidth, kAppHeight, InitialPropertyInstaller::kResize);
}

void AtmMainWidget::SetFrameArrangement() {
  composer_.SetDeltaSize(DeltaSize(delta_width_, delta_height_));
  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
  composer_.ComposeGeometry(MainWidgetGeometry::MainFrame(), ui->main_frame);
  composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(),
                            initial_menu_);
  composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(),
                            description_menu_);
  composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(),
                            registration_menu_);
  composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(), login_menu_);
}

void AtmMainWidget::SetTimeLabelArrangement() {
  composer_.SetShiftFactor(kXFactor, kYFactor);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);
  composer_.ComposeGeometry(MainWidgetGeometry::TimeLabel(), ui->time_label);
}

void AtmMainWidget::RunTimers() { time_timer_->start(kOneSecond); }

void AtmMainWidget::PaintWidgets() {
  QList<QFrame*> frame_list = {ui->main_frame};
  QList<QPushButton*> button_list = {ui->exit_button, ui->minimize_button,
                                     ui->maximize_button};
  QList<QLabel*> label_list = {ui->time_label};

  color_designer_.PaintWidgetSet(frame_list);
  color_designer_.PaintWidgetSet(button_list);
  color_designer_.PaintWidgetSet(label_list);
}

void AtmMainWidget::InitializeObject() {
  time_timer_ = new QTimer(ui->time_label);
  initial_menu_ = new GraphicalInitialMenu(ui->main_frame);
  description_menu_ = new GraphicalDescriptionMenu(ui->main_frame);
  registration_menu_ = new GraphicalRegistrationMenu(ui->main_frame);
  login_menu_ = new GraphicalLoginMenu(ui->main_frame);
}

void AtmMainWidget::ComputeExtraSize() {
  delta_width_ = width() - Geometry::InitialScreenWidth();
  delta_height_ = height() - Geometry::InitialScreenHeight();

  initial_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
  description_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
  registration_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
  login_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
}
