#include <splash_screen_composer.h>

#include <QFont>
#include <QFrame>
#include <QLabel>
#include <QPoint>

#include <conversion_factor.h>
#include <geometry.h>
#include <side.h>
#include <splash_screen_geometry.h>
#include <widget_font.h>

#include <QDebug>

void SplashScreenComposer::SetFrame(QFrame* frame) {
  composer_.SetStretchFactor(1.0, 1.0);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
  composer_.ComposeGeometry(SplashScreenGeometry::SplashScreenFrame(), frame);
}

void SplashScreenComposer::SetVersionLabel(QLabel* version_label) {
  version_label->setText("v1.0.1");
  version_label->setFont(WidgetFont::SetFont(8));

  composer_.SetShiftFactor(1.0, 1.0);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);

  composer_.ComposeGeometry(SplashScreenGeometry::VersionLabel(),
                            version_label);
}

void SplashScreenComposer::SetCompanyNameLabel(QLabel* company_name_label) {
  company_name_label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

  company_name_label->setFont(WidgetFont::SetFont(25));
  composer_.SetShiftFactor(0.5, 1.0);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);

  composer_.ComposeGeometry(SplashScreenGeometry::CompanyNameLabel(),
                            company_name_label);
}

void SplashScreenComposer::SetTextLabel(QLabel* text_label) {
  text_label->setFont(WidgetFont::SetFont(15));

  composer_.SetShiftFactor(0.5, 1.0);
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kShift);

  composer_.ComposeGeometry(SplashScreenGeometry::TextLabel(), text_label);
}

void SplashScreenComposer::SetAtmLabel(QLabel* atm_label) {
  atm_label->setText("ATM");
  atm_label->setFont(WidgetFont::SetFont(75));
  atm_label_stretcher_.StretchAtmLabel(atm_label, delta_size_.Width(),
                                       delta_size_.Height());
}

void SplashScreenComposer::ComputeDeltas(int extra_width, int extra_height) {
  delta_size_.SetWidth(extra_width - Geometry::InitialScreenWidth());
  delta_size_.SetHeight(extra_height - Geometry::InitialScreenHeight());
  composer_.SetDeltaSize(delta_size_);
}

QRect SplashScreenComposer::NewLabelGeometry(const QRect& label) {
  return QRect(label.x() + delta_size_.Width() / 2,
               label.y() + delta_size_.Height(), label.width(), label.height());
}
