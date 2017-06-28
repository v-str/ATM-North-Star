#include <splash_screen_composer.h>

#include <QFont>
#include <QFrame>
#include <QLabel>

#include <geometry.h>

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(Geometry::SplashScreenFrame().x(),
                     Geometry::SplashScreenFrame().y(),
                     Geometry::SplashScreenFrame().width() + delta_width_,
                     Geometry::SplashScreenFrame().height() + delta_height_);
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  version_label->setGeometry(
      Geometry::VersionLabel().x() + delta_width_, Geometry::VersionLabel().y(),
      Geometry::VersionLabel().width(), Geometry::VersionLabel().height());
}

void SplashScreenSizeComposer::ComposeCompanyNameLabel(
    QLabel* company_name_label) {
  company_name_label->setGeometry(
      Geometry::CompanyNameLabel().x() + delta_width_ / 2,
      Geometry::CompanyNameLabel().y(), Geometry::CompanyNameLabel().width(),
      Geometry::CompanyNameLabel().height());
}

void SplashScreenSizeComposer::ComposeSplashScreenLabels(QLabel* date_label,
                                                         QLabel* time_label,
                                                         QLabel* text_label) {
  date_label->setGeometry(NewLabelGeometry(Geometry::DateLabel()));
  time_label->setGeometry(NewLabelGeometry(Geometry::TimeLabel()));
  text_label->setGeometry(NewLabelGeometry(Geometry::TextLabel()));
}

void SplashScreenSizeComposer::ComposeAtmLabel(QLabel* atm_label) {
  atm_label_stretcher_.StretchAtmLabel(atm_label, delta_width_, delta_height_);
}

void SplashScreenSizeComposer::ComputeDeltas(int extra_width,
                                             int extra_height) {
  delta_width_ = extra_width - Geometry::InitialScreenWidth();
  delta_height_ = extra_height - Geometry::InitialScreenHeight();
}

QRect SplashScreenSizeComposer::NewLabelGeometry(const QRect& label) {
  return QRect(label.x() + delta_width_ / 2, label.y() + delta_height_,
               label.width(), label.height());
}
