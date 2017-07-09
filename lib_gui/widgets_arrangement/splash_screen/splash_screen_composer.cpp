#include <splash_screen_composer.h>

#include <QFont>
#include <QFrame>
#include <QLabel>
#include <QPoint>

#include <conversion_factor.h>
#include <geometry.h>
#include <side.h>
#include <splash_screen_geometry.h>

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  //  frame->setGeometry(
  //      SplashScreenGeometry::SplashScreenFrame().x(),
  //      SplashScreenGeometry::SplashScreenFrame().y(),
  //      SplashScreenGeometry::SplashScreenFrame().width() +
  //      delta_size_.Width(),
  //      SplashScreenGeometry::SplashScreenFrame().height() +
  //          delta_size_.Height());

  composer_.SetStretchFactor(1.0, 1.0);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
  composer_.ComposeGeometry(SplashScreenGeometry::SplashScreenFrame(), frame);
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  composer_.SetShiftFactor(1.0, 1.0);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);

  composer_.ComposeGeometry(SplashScreenGeometry::VersionLabel(),
                            version_label);
}

void SplashScreenSizeComposer::ComposeCompanyNameLabel(
    QLabel* company_name_label) {
  composer_.SetShiftFactor(0.5, 1.0);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);

  composer_.ComposeGeometry(SplashScreenGeometry::CompanyNameLabel(),
                            company_name_label);
}

void SplashScreenSizeComposer::ComposeSplashScreenLabels(QLabel* date_label,
                                                         QLabel* time_label,
                                                         QLabel* text_label) {
  composer_.SetShiftFactor(0.5, 1.0);
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kShift);

  composer_.ComposeGeometry(SplashScreenGeometry::DateLabel(), date_label);
  composer_.ComposeGeometry(SplashScreenGeometry::TimeLabel(), time_label);
  composer_.ComposeGeometry(SplashScreenGeometry::TextLabel(), text_label);
}

void SplashScreenSizeComposer::ComposeAtmLabel(QLabel* atm_label) {
  atm_label_stretcher_.StretchAtmLabel(atm_label, delta_size_.Width(),
                                       delta_size_.Height());
}

void SplashScreenSizeComposer::ComputeDeltas(int extra_width,
                                             int extra_height) {
  delta_size_.SetWidth(extra_width - Geometry::InitialScreenWidth());
  delta_size_.SetHeight(extra_height - Geometry::InitialScreenHeight());
  composer_.SetDeltaSize(delta_size_);
}

QRect SplashScreenSizeComposer::NewLabelGeometry(const QRect& label) {
  return QRect(label.x() + delta_size_.Width() / 2,
               label.y() + delta_size_.Height(), label.width(), label.height());
}
