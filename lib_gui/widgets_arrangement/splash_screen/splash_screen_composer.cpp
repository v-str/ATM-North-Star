#include <splash_screen_composer.h>

#include <QFont>
#include <QFontMetrics>
#include <QFrame>
#include <QLabel>

#include <geometry.h>

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(Geometry::SplashScreenFrame().x(), frame->y(),
                     Geometry::SplashScreenFrame().width() + width_increase_,
                     Geometry::SplashScreenFrame().height() + height_increase_);
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  version_label->setGeometry(Geometry::VersionLabel().x() + width_increase_,
                             Geometry::VersionLabel().y(),
                             Geometry::VersionLabel().width(),
                             Geometry::VersionLabel().height());
}

void SplashScreenSizeComposer::ComposeCompanyNameLabel(
    QLabel* company_name_label) {
  company_name_label->setGeometry(
      Geometry::CompanyNameLabel().x() + width_increase_ / 2,
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
  atm_label_stretcher_.StretchAtmLabel(atm_label, width_increase_,
                                       height_increase_);
}

void SplashScreenSizeComposer::ComputeSizeIncrease(int extra_width,
                                                   int extra_height) {
  width_increase_ = extra_width - kSplashScreenWidth;
  height_increase_ = extra_height - kSplashScreenHeight;
}

QRect SplashScreenSizeComposer::NewLabelGeometry(const QRect& label) {
  return QRect(label.x() + width_increase_ / 2, label.y() + height_increase_,
               label.width(), label.height());
}
