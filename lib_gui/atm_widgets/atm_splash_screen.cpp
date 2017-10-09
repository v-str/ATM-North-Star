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

#include <date_label.h>
#include <exit_dialog.h>
#include <initial_property_installer.h>
#include <space_block_filter.h>
#include <splash_screen_geometry.h>
#include <text_color_swapper.h>
#include <time_label.h>
#include <timedate_changer.h>
#include <widget_font.h>

AtmSplashScreen::AtmSplashScreen(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::AtmSplashScreen),
      exit_dialog_(new ExitDialog(this)) {
  ui->setupUi(this);
  exit_dialog_->setModal(true);

  setWindowTitle("ATM splash screen");

  SetInitialSettings();
  TuneWidgets();
  SetConnections();
  RunTimers();
}

AtmSplashScreen::~AtmSplashScreen() {
  delete ui;
  delete color_swap_timer_;
  delete text_color_swapper_;
  delete time_label_;
  delete date_label_;
}

void AtmSplashScreen::SetCompanyName(const QString& atm_company_name) {
  ui->atm_company_name_label->setText(atm_company_name);
}

void AtmSplashScreen::UnlockFixedGeometry() { setMinimumSize(0, 0); }

void AtmSplashScreen::BlinkAtmLabelColor() {
  text_color_swapper_->SwapColors(ui->atm_label);
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
  text_color_swapper_ = new TextColorSwapper;
  time_label_ = new TimeLabel(static_cast<QLabel*>(ui->frame));
  date_label_ = new DateLabel(static_cast<QLabel*>(ui->frame));
}

void AtmSplashScreen::PaintWidgets() {
  QList<QLabel*> label_list = {
      ui->atm_company_name_label, ui->text_label, date_label_, time_label_,
      ui->version_label,          ui->atm_label};
  QList<QFrame*> frame_list = {ui->frame};

  color_designer_.PaintWidgetSet(&label_list);
  color_designer_.PaintWidgetSet(&frame_list);
}

void AtmSplashScreen::SetBackgroundColor() {
  color_designer_.SetBackground(this);
}

void AtmSplashScreen::SetImages() {
  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);
  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmSplashScreen::TuneWidgets() {
  InitialPropertyInstaller::SetInitialProperties(
      this, kWidgetWidth, kWidgetHeight, InitialPropertyInstaller::kResize);

  SetFonts();

  time_label_->setGeometry(SplashScreenGeometry::TimeLabel());
  date_label_->setGeometry(SplashScreenGeometry::DateLabel());
  ui->atm_label->setGeometry(SplashScreenGeometry::AtmLabel());
}

void AtmSplashScreen::SetFonts() {
  ui->atm_company_name_label->setFont(WidgetFont::SetFont(25));
  ui->atm_label->setFont(WidgetFont::SetFont(75));
}

void AtmSplashScreen::SetConnections() {
  connect(color_swap_timer_, SIGNAL(timeout()), SLOT(BlinkAtmLabelColor()));
  connect(this, SIGNAL(Exit()), SLOT(ShowExitWidget()));
  connect(this, SIGNAL(EnterIsPressed()), SLOT(UnlockFixedGeometry()));
}

void AtmSplashScreen::RunTimers() { color_swap_timer_->start(kTimerValue); }

void AtmSplashScreen::ProcessEnterKey() {
  emit PassPosition(geometry());
  emit EnterIsPressed();

  if (isMaximized()) {
    emit MaximizedScreen(true);
  }
}

void AtmSplashScreen::ComputeNewGeometry() {
  composer_.ComputeDeltas(width(), height());
}

void AtmSplashScreen::ResizeWidgets() {
  composer_.SetFrame(ui->frame);
  composer_.SetVersionLabel(ui->version_label);
  composer_.SetCompanyNameLabel(ui->atm_company_name_label);
  composer_.SetSplashScreenLabels(date_label_, time_label_, ui->text_label);
  composer_.SetAtmLabel(ui->atm_label);
}
