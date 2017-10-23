#include <splash_screen_frame.h>

#include <QLabel>
#include <QList>
#include <QString>
#include <QTimer>

#include <atm_composer.h>
#include <side.h>
#include <splash_screen_geometry.h>
#include <text_color_swapper.h>

SplashScreenFrame::SplashScreenFrame(QWidget* parent)
    : BaseAtmFrame(parent, kBackButtonDeactivated) {
  SetSplashScreenSettings();
  InitializeObjects();
  TuneLabel();
  PaintWidgets();
  SetConnection();

  color_swap_timer_->start(kBlinkTime);
}

SplashScreenFrame::~SplashScreenFrame() {
  delete color_swap_timer_;
  delete text_color_swapper_;
}

void SplashScreenFrame::SetCompanyName(const QString& company_name) {
  company_name_label_->setText(company_name);
}

void SplashScreenFrame::ChangeGeometry() {
  composer_.SetDeltaSize(AtmComposer::GetDeltaSize());

  AtmComposer::StretchWidget(SplashScreenGeometry::SplashScreenFrame(),
                             Side::kRight | Side::kDown, 1.0, 1.0, this);

  composer_.ComposeCompanyNameLabel(company_name_label_);
  composer_.ComposeAtmLabel(atm_label_);
  composer_.ComposeTextLabel(text_label_);
}

void SplashScreenFrame::BlinkAtmLabelColor() {
  text_color_swapper_->SwapColors(atm_label_);
}

void SplashScreenFrame::SetSplashScreenSettings() {
  SetInitialFrameGeometry(SplashScreenGeometry::SplashScreenFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, this);
}

void SplashScreenFrame::InitializeObjects() {
  version_label_ = new QLabel(this);
  company_name_label_ = new QLabel(this);
  atm_label_ = new QLabel(this);
  text_label_ = new QLabel(this);

  color_swap_timer_ = new QTimer(atm_label_);
  text_color_swapper_ = new TextColorSwapper;
}

void SplashScreenFrame::TuneLabel() {
  composer_.TuneLabels(version_label_, company_name_label_, text_label_,
                       atm_label_);
}

void SplashScreenFrame::PaintWidgets() {
  QList<QLabel*> label_list = {version_label_, company_name_label_, atm_label_,
                               text_label_};

  color_designer_.PaintWidgetSet(&label_list);
}

void SplashScreenFrame::SetConnection() {
  connect(color_swap_timer_, SIGNAL(timeout()), SLOT(BlinkAtmLabelColor()));
}
