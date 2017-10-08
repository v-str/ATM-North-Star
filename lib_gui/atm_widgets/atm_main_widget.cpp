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
#include <time_label.h>
#include <timedate_changer.h>
#include <widget_font.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);

  setWindowTitle("ATM");

  SetInitialSettings();
  SetWidgetProperties();
  SetConnections();
}

AtmMainWidget::~AtmMainWidget() {
  delete ui;
  delete time_label_;
  delete date_label_;
}

void AtmMainWidget::resizeEvent(QResizeEvent*) {
  ComputeExtraSize();
  SetFrameArrangement();
  SetTimeDateArrangement();
}

void AtmMainWidget::SetInitialSettings() {
  InitializeObject();
  PaintWidgets();
  SetBackgroundColor();
  SetImages();

  setMinimumSize(kAppWidth, kAppHeight);

  registration_menu_->close();
  login_menu_->close();
}

void AtmMainWidget::InitializeObject() {
  time_label_ = new TimeLabel(static_cast<QLabel*>(ui->main_frame));
  date_label_ = new DateLabel(static_cast<QLabel*>(ui->main_frame));
  initial_menu_ = new GraphicalInitialMenu(ui->main_frame);
  registration_menu_ = new GraphicalRegistrationMenu(ui->main_frame);
  login_menu_ = new GraphicalLoginMenu(ui->main_frame);
}

void AtmMainWidget::PaintWidgets() {
  QList<QFrame*> frame_list = {ui->main_frame};
  QList<QLabel*> label_list = {time_label_, date_label_};

  color_designer_.PaintWidgetSet(&frame_list);
  color_designer_.PaintWidgetSet(&label_list);
}

void AtmMainWidget::SetBackgroundColor() {
  color_designer_.SetBackground(this);
}

void AtmMainWidget::SetImages() {
  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);

  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmMainWidget::SetWidgetProperties() {
  InitialPropertyInstaller::SetInitialProperties(
      this, kAppWidth, kAppHeight, InitialPropertyInstaller::kResize);

  time_label_->setGeometry(MainWidgetGeometry::TimeLabel());
  date_label_->setGeometry(MainWidgetGeometry::DateLabel());

  time_label_->setFont(WidgetFont::SetFont(12));
  date_label_->setFont(WidgetFont::SetFont(12));

  time_label_->setAlignment(Qt::AlignRight);
  date_label_->setAlignment(Qt::AlignRight);
}

void AtmMainWidget::SetConnections() {
  connect(initial_menu_, SIGNAL(RegistrationButtonClicked()),
          registration_menu_, SLOT(Show()));
  connect(initial_menu_, SIGNAL(LoginButtonClicked()), login_menu_,
          SLOT(Show()));
  connect(registration_menu_, SIGNAL(BackButtonClicked()), initial_menu_,
          SLOT(Show()));
  connect(login_menu_, SIGNAL(BackButtonClicked()), initial_menu_,
          SLOT(Show()));
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
                            registration_menu_);
  composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(), login_menu_);
}

void AtmMainWidget::SetTimeDateArrangement() {
  composer_.SetShiftFactor(kXFactor, kYFactor);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);
  composer_.ComposeGeometry(MainWidgetGeometry::TimeLabel(), time_label_);

  composer_.SetShiftFactor(kXFactor, kYFactor);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);
  composer_.ComposeGeometry(MainWidgetGeometry::DateLabel(), date_label_);
}

void AtmMainWidget::ComputeExtraSize() {
  delta_width_ = width() - Geometry::InitialScreenWidth();
  delta_height_ = height() - Geometry::InitialScreenHeight();

  initial_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
  registration_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
  login_menu_->SetDeltaSize(DeltaSize(delta_width_, delta_height_));
}
