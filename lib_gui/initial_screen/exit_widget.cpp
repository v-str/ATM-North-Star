#include <exit_widget.h>
#include <ui_exit_widget.h>

#include <QTimer>

#include <initial_property_installer.h>

ExitWidget::ExitWidget(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::ExitWidget),
      timer_(new QTimer),
      text_animation_(new TextAnimation) {
  ui->setupUi(this);

  connect(timer_, SIGNAL(timeout()), SLOT(AnimateText()));
  connect(this, SIGNAL(EndText()), timer_, SLOT(stop()));

  timer_->start();
}

ExitWidget::~ExitWidget() {
  delete ui;
  delete timer_;
  delete text_animation_;
}

void ExitWidget::AnimateText() {
  if (!text_animation_->WriteTextWithDelay(ui->message_screen, timer_, 100)) {
    emit EndText();
  }
}

void ExitWidget::SetInitialProperties() {
  InitialPropertyInstaller::InstallInitialProperies(this, 300, 150);
}
