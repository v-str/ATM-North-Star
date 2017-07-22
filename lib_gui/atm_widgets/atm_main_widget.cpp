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

#include <demo_menu.h>
#include <demo_menu_geometry.h>
#include <geometry.h>
#include <initial_frame_geometry.h>
#include <initial_menu.h>
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

void AtmMainWidget::SetBackgroundColor() {
  color_designer_.SetBackgroundColor(this);
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

void AtmMainWidget::ShowDemoMenu() {
  demo_menu_ = new DemoMenu(ui->main_frame);
  demo_menu_->setGeometry(DemoMenuGeometry::DemoFrame());
  demo_menu_->show();
}

void AtmMainWidget::resizeEvent(QResizeEvent*) {
  ComputeExtraSize();
  SetFrameArrangement();
  SetTimeLabelArrangement();
}

void AtmMainWidget::SetConnections() {
  connect(ui->maximize_button, SIGNAL(clicked(bool)),
          SLOT(MaximizeButtonClicked(bool)));
  connect(time_timer_, SIGNAL(timeout()), SLOT(TickTime()));
  connect(initial_menu_, SIGNAL(AlreadyClosed()), SLOT(ShowDemoMenu()));
}

void AtmMainWidget::SetInitialSettings() {
  InitializeObject();
  PaintWidgets();
  SetBackgroundColor();
  SetImages();

  initial_menu_->setGeometry(InitialFrameGeometry::InitialFrame());
}

void AtmMainWidget::SetWidgetProperties() {
  setMinimumSize(600, 400);
  InitialPropertyInstaller::SetInitialProperties(
      this, 600, 400, InitialPropertyInstaller::kResize);
}

void AtmMainWidget::SetFrameArrangement() {
  composer_.SetStretchFactor(1.0, 1.0);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);

  composer_.ComposeGeometry(MainWidgetGeometry::MainFrame(), ui->main_frame);

  composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(),
                            initial_menu_);
}

void AtmMainWidget::SetTimeLabelArrangement() {
  composer_.SetShiftFactor(1.0, 1.0);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);

  composer_.ComposeGeometry(MainWidgetGeometry::TimeLabel(), ui->time_label);
}

void AtmMainWidget::RunTimers() { time_timer_->start(1000); }

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
  initial_menu_ = new InitialMenu(ui->main_frame);
}

void AtmMainWidget::ComputeExtraSize() {
  int delta_width = width() - Geometry::InitialScreenWidth();
  int delta_height = height() - Geometry::InitialScreenHeight();

  composer_.SetDeltaSize(DeltaSize(delta_width, delta_height));
  initial_menu_->SetDeltaSize(DeltaSize(delta_width, delta_height));
}
