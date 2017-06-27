#include <splash_screen_composer.h>

#include <QFont>
#include <QFontMetrics>
#include <QFrame>
#include <QLabel>

#include <geometry.h>

QRect SplashScreenSizeComposer::kVersionLabel(485, 17, 100, 15);
QRect SplashScreenSizeComposer::kCompanyNameLabel(35, 40, 510, 70);
QRect SplashScreenSizeComposer::kDateLabel(140, 360, 160, 20);
QRect SplashScreenSizeComposer::kTimeLabel(300, 360, 160, 20);
QRect SplashScreenSizeComposer::kTextLabel(150, 270, 280, 30);
QRect SplashScreenSizeComposer::kFrame(10, 10, 580, 380);

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(kFrame.x(), frame->y(), kFrame.width() + width_increase_,
                     kFrame.height() + height_increase_);
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
      kCompanyNameLabel.x() + width_increase_ / 2, company_name_label->y(),
      company_name_label->width(), company_name_label->height());
}

void SplashScreenSizeComposer::ComposeSplashScreenLabels(QLabel* date_label,
                                                         QLabel* time_label,
                                                         QLabel* text_label) {
  date_label->setGeometry(NewLabelGeometry(kDateLabel));
  time_label->setGeometry(NewLabelGeometry(kTimeLabel));
  text_label->setGeometry(NewLabelGeometry(kTextLabel));
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
