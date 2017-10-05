#include <atm_splash_screen.h>
#include <ui_atm_splash_screen.h>

#include <QApplication>
#include <QCursor>
#include <QIcon>
#include <QKeyEvent>
#include <QList>
#include <QPixmap>
#include <QString>
#include <QTimer>

#include <exit_dialog.h>
#include <initial_property_installer.h>
#include <space_block_filter.h>
#include <text_color_swapper.h>
#include <timedate_changer.h>

AtmSplashScreen::AtmSplashScreen(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::AtmSplashScreen),
      exit_dialog_(new ExitDialog(this)) {
  ui->setupUi(this);
  exit_dialog_->setModal(true);

  setWindowTitle("ATM splash screen");

  SetInitialSettings();
  SetWidgetProperties();
  SetConnections();
  RunTimers();
}

AtmSplashScreen::~AtmSplashScreen() {
  delete ui;
  delete color_swap_timer_;
  delete text_color_swapper_;
  delete date_timer_;
  delete time_timer_;
}

void AtmSplashScreen::SetCompanyName(const QString& atm_company_name) {
  ui->atm_company_name_label->setText(atm_company_name);
}

void AtmSplashScreen::UnlockFixedGeometry() { setMinimumSize(0, 0); }

void AtmSplashScreen::BlinkAtmLabelColor() {
  text_color_swapper_->SwapColors(ui->atm_label);
}

void AtmSplashScreen::TickTime() {
  TimeDateChanger::ChangeDate(ui->date_label);
  TimeDateChanger::ChangeTime(ui->time_label);
}

void AtmSplashScreen::ShowExitWidget() {
  exit_dialog_->ShowWidgetOnCenterAt(geometry());
}

void AtmSplashScreen::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Escape:
      emit Exit();
    case Qt::Key_Space:
      event->ignore();
      break;
    case Qt::Key_Enter:
      ProcessEnterKey();
      break;
    case Qt::Key_Return:
      ProcessEnterKey();
    default:
      break;
  }
  QWidget::keyPressEvent(event);
}

void AtmSplashScreen::resizeEvent(QResizeEvent*) {
  ComputeNewGeometry();
  ResizeWidgets();
}

void AtmSplashScreen::SetInitialSettings() {
  InitializeObjects();
  PaintWidgets();
  SetBackgroundColor();
  SetImages();

  setMinimumSize(kWidgetWidth, kWidgetHeight);

  SetCompanyName("");
}

void AtmSplashScreen::InitializeObjects() {
  color_swap_timer_ = new QTimer(ui->atm_label);
  text_color_swapper_ = new TextColorSwapper();
  date_timer_ = new QTimer(ui->date_label);
  time_timer_ = new QTimer(ui->time_label);
}

void AtmSplashScreen::PaintWidgets() {
  QList<QLabel*> label_list = {ui->atm_company_name_label, ui->text_label,
                               ui->date_label, ui->time_label,
                               ui->version_label};
  QList<QFrame*> frame_list = {ui->frame};

  color_designer_.PaintWidgetSet(label_list);
  color_designer_.PaintWidgetSet(frame_list);
}

void AtmSplashScreen::SetBackgroundColor() {
  color_designer_.SetBackground(this);
}

void AtmSplashScreen::SetImages() {
  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);
  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmSplashScreen::SetWidgetProperties() {
  InitialPropertyInstaller::SetInitialProperties(
      this, kWidgetWidth, kWidgetHeight, InitialPropertyInstaller::kResize);
}

void AtmSplashScreen::SetConnections() {
  connect(color_swap_timer_, SIGNAL(timeout()), SLOT(BlinkAtmLabelColor()));
  connect(date_timer_, SIGNAL(timeout()), SLOT(TickTime()));
  connect(time_timer_, SIGNAL(timeout()), SLOT(TickTime()));
  connect(this, SIGNAL(Exit()), SLOT(ShowExitWidget()));
  connect(this, SIGNAL(EnterIsPressed()), SLOT(UnlockFixedGeometry()));
}

void AtmSplashScreen::RunTimers() {
  color_swap_timer_->start(kTimerValue);
  date_timer_->start(kOneSecond);
  time_timer_->start(kOneSecond);
}

void AtmSplashScreen::ProcessEnterKey() {
  QRect position = {x(), frameGeometry().y(), width(), height()};

  emit PassPositionForAnimation(geometry());
  emit PassPosition(position);
  emit EnterIsPressed();
}

void AtmSplashScreen::ComputeNewGeometry() {
  composer_.ComputeDeltas(width(), height());
}

void AtmSplashScreen::ResizeWidgets() {
  composer_.ComposeFrame(ui->frame);
  composer_.ComposeVersionLabel(ui->version_label);
  composer_.ComposeCompanyNameLabel(ui->atm_company_name_label);
  composer_.ComposeSplashScreenLabels(ui->date_label, ui->time_label,
                                      ui->text_label);
  composer_.ComposeAtmLabel(ui->atm_label);
}
