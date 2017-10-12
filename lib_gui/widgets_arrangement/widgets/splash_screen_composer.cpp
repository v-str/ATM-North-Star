#include <splash_screen_composer.h>

#include <QFont>
#include <QFrame>
#include <QLabel>
#include <QPoint>

#include <conversion_factor.h>
#include <side.h>
#include <splash_screen_geometry.h>
#include <widget_font.h>

void SplashScreenComposer::TuneLabels(QLabel* version_label,
                                      QLabel* company_name_label,
                                      QLabel* text_label, QLabel* atm_label) {
  version_label->setText("v1.0.1");
  version_label->setFont(WidgetFont::SetFont(8));
  version_label->setGeometry(SplashScreenGeometry::VersionLabel());

  company_name_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  company_name_label->setFont(WidgetFont::SetFont(25));
  company_name_label->setGeometry(SplashScreenGeometry::CompanyNameLabel());

  text_label->setFont(WidgetFont::SetFont(15));
  text_label->setText("Press <Enter> to start");
  text_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  atm_label->setText("ATM");
  atm_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  atm_label->setFont(WidgetFont::SetFont(55));
}

void SplashScreenComposer::SetFrame(QFrame* frame) {
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
}

void SplashScreenComposer::ComputeDeltas(int extra_width, int extra_height) {
  delta_size_.SetWidth(extra_width -
                       SplashScreenGeometry::SplashScreenFrame().width());
  delta_size_.SetHeight(extra_height -
                        SplashScreenGeometry::SplashScreenFrame().height());
  composer_.SetDeltaSize(delta_size_);
}

QRect SplashScreenComposer::NewLabelGeometry(const QRect& label) {
  return QRect(label.x() + delta_size_.Width() / 2,
               label.y() + delta_size_.Height(), label.width(), label.height());
}
