#include <splash_screen_composer.h>

#include <QFont>
#include <QFrame>
#include <QLabel>
#include <QPoint>

#include <conversion_factor.h>
#include <initial_geometry.h>

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(
      InitialGeometry::SplashScreenFrame().x(),
      InitialGeometry::SplashScreenFrame().y(),
      InitialGeometry::SplashScreenFrame().width() + delta_size_.Width(),
      InitialGeometry::SplashScreenFrame().height() + delta_size_.Height());
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  shifter_.ShiftWidget(ConversionFactor(1.0, 0.0),
                       InitialGeometry::VersionLabel(),
                       WidgetShifter::kShiftRight, version_label);
}

void SplashScreenSizeComposer::ComposeCompanyNameLabel(
    QLabel* company_name_label) {
  shifter_.ShiftWidget(ConversionFactor(0.5, 0.0),
                       InitialGeometry::CompanyNameLabel(),
                       WidgetShifter::kShiftRight, company_name_label);
}

void SplashScreenSizeComposer::ComposeSplashScreenLabels(QLabel* date_label,
                                                         QLabel* time_label,
                                                         QLabel* text_label) {
  shifter_.ShiftWidget(ConversionFactor(0.5, 1.0), InitialGeometry::DateLabel(),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       date_label);
  shifter_.ShiftWidget(ConversionFactor(0.5, 1.0), InitialGeometry::TimeLabel(),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       time_label);
  shifter_.ShiftWidget(ConversionFactor(0.5, 1.0), InitialGeometry::TextLabel(),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       text_label);
}

void SplashScreenSizeComposer::ComposeAtmLabel(QLabel* atm_label) {
  atm_label_stretcher_.StretchAtmLabel(atm_label, delta_size_.Width(),
                                       delta_size_.Height());
}

void SplashScreenSizeComposer::ComputeDeltas(int extra_width,
                                             int extra_height) {
  delta_size_.SetWidth(extra_width - InitialGeometry::InitialScreenWidth());
  delta_size_.SetHeight(extra_height - InitialGeometry::InitialScreenHeight());
  shifter_.SetDeltaSize(delta_size_);
}

QRect SplashScreenSizeComposer::NewLabelGeometry(const QRect& label) {
  return QRect(label.x() + delta_size_.Width() / 2,
               label.y() + delta_size_.Height(), label.width(), label.height());
}
