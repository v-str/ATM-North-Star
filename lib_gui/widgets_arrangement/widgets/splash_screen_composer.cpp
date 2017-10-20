#include <splash_screen_composer.h>

#include <QFrame>
#include <QLabel>

#include <side.h>
#include <splash_screen_geometry.h>
#include <widget_font.h>

#include <QDebug>

void SplashScreenComposer::TuneLabels(QLabel* version_label,
                                      QLabel* company_name_label,
                                      QLabel* text_label,
                                      QLabel* atm_label) {
  version_label->setText("v1.0.1");
  version_label->setGeometry(SplashScreenGeometry::VersionLabel());
  version_label->setFont(WidgetFont::SetFont(8));

  company_name_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  company_name_label->setGeometry(SplashScreenGeometry::CompanyNameLabel());
  company_name_label->setFont(WidgetFont::SetFont(25));

  text_label->setText("Press <Enter> to start");
  text_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  text_label->setFont(WidgetFont::SetFont(15));

  atm_label->setText("ATM");
  atm_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  atm_label->setFont(WidgetFont::SetFont());
}

void SplashScreenComposer::ComposeFrame(QFrame* frame) {
  composer_.SetStretchFactor(1.0, 1.0);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
  composer_.ComposeGeometry(SplashScreenGeometry::SplashScreenFrame(), frame);
}

void SplashScreenComposer::ComposeCompanyNameLabel(QLabel* company_name_label) {
  composer_.SetShiftFactor(0.5, 1.0);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);

  composer_.ComposeGeometry(SplashScreenGeometry::CompanyNameLabel(),
                            company_name_label);
}

void SplashScreenComposer::ComposeTextLabel(QLabel* text_label) {
  composer_.SetShiftFactor(0.5, 1.0);
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kShift);

  composer_.ComposeGeometry(SplashScreenGeometry::TextLabel(), text_label);
}

void SplashScreenComposer::ComposeAtmLabel(QLabel* atm_label) {
  atm_label_stretcher_.StretchAtmLabel(atm_label, delta_size_.Width(),
                                       delta_size_.Height());

  qDebug() << delta_size_.Width() << " " << delta_size_.Height();
}

void SplashScreenComposer::SetDeltaSize(const DeltaSize& delta_size) {
  composer_.SetDeltaSize(delta_size);
  delta_size_ = delta_size;
}
