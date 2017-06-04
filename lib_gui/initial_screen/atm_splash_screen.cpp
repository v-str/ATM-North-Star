#include <atm_splash_screen.h>
#include <ui_atm_splash_screen.h>

#include <QApplication>
#include <QCoreApplication>
#include <QIcon>
#include <QKeyEvent>
#include <QPoint>
#include <QString>
#include <QTimer>

#include <close_block_filter.h>
#include <exit_dialog.h>
#include <initial_property_installer.h>
#include <painter.h>
#include <text_color_swapper.h>
#include <timedate_changer.h>

AtmSplashScreen::AtmSplashScreen(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::AtmSplashScreen),
      exit_dialog_(new ExitDialog(this)),
      blink_color_one_("black"),
      blink_color_two_("grey") {
  ui->setupUi(this);
  exit_dialog_->setModal(true);

  setWindowTitle("Atm");

  InitializeObjects();
  SetWidgetAppearance();
  BlockKeys();
  InitialSettings();
  SetConnections();
  RunTimers();
}

AtmSplashScreen::~AtmSplashScreen() {
  delete ui;
  delete color_swap_timer_;
  delete color_swapper_;
  delete time_date_timer_;
}

void AtmSplashScreen::SetCompanyName(const QString& atm_company_name) {
  ui->atm_company_name_label->setText(atm_company_name);
}

void AtmSplashScreen::SetSplashScreenAppearance(
    const QString& main_color,
    const QString& secondary_color,
    const QString& additional_color) {
  Painter::ChangeLabelColor(ui->atm_company_name_label, main_color);
  Painter::ChangeLabelColor(ui->text_label, main_color);
  Painter::ChangeLabelColor(ui->timedate_label, main_color);
  Painter::ChangeLabelColor(ui->version_label, main_color);
  Painter::ChangeButtonColor(ui->exit_button, main_color, secondary_color,
                             additional_color);
  Painter::ChangeFrameColor(ui->frame, main_color);
  exit_dialog_->SetExitDialogAppearance(main_color, secondary_color,
                                        additional_color);
}

void AtmSplashScreen::SetAtmBlinkColor(const QString& color_one,
                                       const QString& color_two) {
  blink_color_one_ = color_one;
  blink_color_two_ = color_two;
  emit BlinkColor();
}

void AtmSplashScreen::SetBackgroundImage(const QString& background_image) {
  Painter::ChangeBackgroundImage(this, background_image);
  exit_dialog_->SetBackgroundImage(background_image);
}

void AtmSplashScreen::SetBackgroundColor(const QString& background_color) {
  Painter::ChangeBackgroundColor(this, background_color);
  exit_dialog_->SetBackgroundColor(background_color);
}

bool AtmSplashScreen::IsMainWidgetReadyToShow() {
  return main_widget_launch_condition_;
}

void AtmSplashScreen::AtmBlinkColor() {
  color_swapper_->ChangeColor(ui->atm_label, blink_color_one_,
                              blink_color_two_);
}

void AtmSplashScreen::ChangeTimeDate() {
  TimeDateChanger::ChangeTimeData(ui->timedate_label);
}

void AtmSplashScreen::ShowExitWidget() {
  exit_dialog_->ShowWidgetOnCenterAt(geometry());
}

void AtmSplashScreen::CloseBeforeMainWidget() {
  main_widget_launch_condition_ = true;
  close();
}

void AtmSplashScreen::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Escape:
      emit Exit();
    case Qt::Key_Space:
      event->ignore();
      break;
    case Qt::Key_Enter:
      emit EnterIsPressed(this->geometry());
      break;
    case Qt::Key_Return:
      emit EnterIsPressed(this->geometry());
    default:
      break;
  }
  QWidget::keyPressEvent(event);
}

void AtmSplashScreen::InitialSettings() {
  SetCompanyName();
  SetSplashScreenAppearance();
  SetAtmBlinkColor();
  SetBackgroundImage();
}

void AtmSplashScreen::SetWidgetAppearance() {
  InitialPropertyInstaller::SetInitialProperties(this, 600, 400);
  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmSplashScreen::SetConnections() {
  connect(this, SIGNAL(BlinkColor()), SLOT(AtmBlinkColor()));
  connect(color_swap_timer_, SIGNAL(timeout()), SLOT(AtmBlinkColor()));
  connect(time_date_timer_, SIGNAL(timeout()), SLOT(ChangeTimeDate()));
  connect(this, SIGNAL(Exit()), SLOT(ShowExitWidget()));
  connect(ui->exit_button, SIGNAL(clicked(bool)), SLOT(ShowExitWidget()));
}

void AtmSplashScreen::InitializeObjects() {
  color_swap_timer_ = new QTimer(ui->atm_label);
  color_swapper_ = new TextColorSwapper();
  time_date_timer_ = new QTimer(ui->timedate_label);
}

void AtmSplashScreen::RunTimers() {
  color_swap_timer_->start(350);
  time_date_timer_->start(1000);
}

void AtmSplashScreen::BlockKeys() {
  ui->exit_button->installEventFilter(new CloseBlockFilter(ui->exit_button));
}
