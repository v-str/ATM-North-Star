#include <atm_splash_screen.h>
#include <ui_atm_splash_screen.h>

#include <QApplication>
#include <QCoreApplication>
#include <QIcon>
#include <QKeyEvent>
#include <QList>
#include <QPoint>
#include <QString>
#include <QTimer>

#include <close_block_filter.h>
#include <exit_dialog.h>
#include <initial_property_installer.h>
#include <painter.h>
#include <text_color_swapper.h>
#include <timedate_changer.h>
#include <widget_color.h>

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
  PaintWidgets();
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
  WidgetColor widget_color(main_color, secondary_color, additional_color);
  color_designer_.CustomizeColorSet(widget_color);

  PaintWidgets();

  exit_dialog_->SetExitDialogAppearance(main_color, secondary_color,
                                        additional_color);
}

void AtmSplashScreen::SetAtmBlinkColor(const QString& color_one,
                                       const QString& color_two) {
  blink_color_one_ = color_one;
  blink_color_two_ = color_two;
  emit BlinkColor();
}

void AtmSplashScreen::SetBackgroundColor(const QString& background_color) {
  Painter::ChangeBackgroundColor(this, background_color);
  exit_dialog_->SetBackgroundColor(background_color);
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

void AtmSplashScreen::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Escape:
      emit Exit();
    case Qt::Key_Space:
      event->ignore();
      break;
    case Qt::Key_Enter:
      emit PassPositionWhenEnterPressed(this->geometry());
      break;
    case Qt::Key_Return:
      emit PassPositionWhenEnterPressed(this->geometry());
    default:
      break;
  }
  QWidget::keyPressEvent(event);
}

void AtmSplashScreen::InitialSettings() {
  SetCompanyName();
  SetAtmBlinkColor();
}

void AtmSplashScreen::SetWidgetAppearance() {
  InitialPropertyInstaller::SetInitialProperties(this, 600, 400);
  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmSplashScreen::PaintWidgets() {
  QList<QLabel*> label_list = {ui->atm_company_name_label, ui->text_label,
                               ui->timedate_label, ui->version_label};
  QList<QPushButton*> button_list = {ui->exit_button};
  QList<QFrame*> frame_list = {ui->frame};

  color_designer_.PaintWidgetSet(label_list);
  color_designer_.PaintWidgetSet(button_list);
  color_designer_.PaintWidgetSet(frame_list);
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
