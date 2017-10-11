#include <splash_screen_frame.h>

#include <QLabel>
#include <QList>
#include <QString>

#include <side.h>
#include <splash_screen_geometry.h>

SplashScreenFrame::SplashScreenFrame(QWidget *parent)
    : BaseAtmFrame(parent, kBackButtonDeactivated) {
  SetSplashScreenSettings();
  InitializeLabels();
  TuneLabel();
  PaintWidgets();
}

SplashScreenFrame::~SplashScreenFrame() {}

void SplashScreenFrame::SetCompanyName(const QString &company_name) {
  company_name_label_->setText(company_name);
}

void SplashScreenFrame::resizeEvent(QResizeEvent *) {
  composer_.ComputeDeltas(width(), height());

  composer_.ComposeCompanyNameLabel(company_name_label_);
  composer_.ComposeAtmLabel(atm_label_);
  composer_.ComposeTextLabel(text_label_);
}

void SplashScreenFrame::SetSplashScreenSettings() {
  SetInitialFrameGeometry(SplashScreenGeometry::SplashScreenFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, kHalfASecond, this);
}

void SplashScreenFrame::InitializeLabels() {
  version_label_ = new QLabel(this);
  company_name_label_ = new QLabel(this);
  atm_label_ = new QLabel(this);
  text_label_ = new QLabel(this);
}

void SplashScreenFrame::TuneLabel() {
  composer_.TuneLabels(version_label_, company_name_label_, text_label_,
                       atm_label_);
}

void SplashScreenFrame::PaintWidgets() {
  QList<QLabel *> label_list = {version_label_, company_name_label_, atm_label_,
                                text_label_};

  color_designer_.PaintWidgetSet(&label_list);
}
