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

#include <initial_menu.h>
#include <initial_property_installer.h>
#include <painter.h>
#include <timedate_changer.h>

QRect AtmMainWidget::kTimeLabel = {470, 5, 114, 20};
QRect AtmMainWidget::kMainFrame = {5, 5, 590, 390};
QRect AtmMainWidget::kInitialFrame = {5, 30, 580, 355};

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

void AtmMainWidget::resizeEvent(QResizeEvent*) {
  ComputeExtraSize();
  SetFrameArrangement();
  SetTimeLabelArrangement();
}

void AtmMainWidget::SetConnections() {
  connect(ui->maximize_button, SIGNAL(clicked(bool)),
          SLOT(MaximizeButtonClicked(bool)));
  connect(time_timer_, SIGNAL(timeout()), SLOT(TickTime()));
}

void AtmMainWidget::SetInitialSettings() {
  InitializeObject();
  PaintWidgets();
  SetBackgroundColor();
  SetImages();

  initial_menu_->setGeometry(kInitialFrame);
}

void AtmMainWidget::SetWidgetProperties() {
  setMinimumSize(600, 400);
  InitialPropertyInstaller::SetInitialProperties(
      this, 600, 400, InitialPropertyInstaller::kResize);
}

void AtmMainWidget::SetFrameArrangement() {
  ui->main_frame->setGeometry(kMainFrame.x(), kMainFrame.y(),
                              kMainFrame.width() + extra_width_,
                              kMainFrame.height() + extra_height_);

  initial_menu_->SetExtraGeometryParameters(extra_width_, extra_height_);
  initial_menu_->setGeometry(kInitialFrame.x(), kInitialFrame.y(),
                             kInitialFrame.width() + extra_width_,
                             kInitialFrame.height() + extra_height_);
}

void AtmMainWidget::SetTimeLabelArrangement() {
  ui->time_label->setGeometry(kTimeLabel.x() + extra_width_, kTimeLabel.y(),
                              kTimeLabel.width(), kTimeLabel.height());
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
  extra_width_ = width() - kWidth;
  extra_height_ = height() - kHeight;
}
