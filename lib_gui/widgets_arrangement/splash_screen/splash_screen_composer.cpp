#include <splash_screen_composer.h>

#include <QFont>
#include <QFrame>
#include <QLabel>
#include <QPoint>

#include <geometry.h>
#include <conversion_factor.h>

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(
      Geometry::SplashScreenFrame().x(), Geometry::SplashScreenFrame().y(),
      Geometry::SplashScreenFrame().width() + delta_size_.Width(),
      Geometry::SplashScreenFrame().height() + delta_size_.Height());
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  shifter_.ShiftWidget(ConversionFactor(1.0, 0.0), WidgetShifter::kShiftRight,
                       Geometry::VersionLabel(), version_label);
}

void SplashScreenSizeComposer::ComposeCompanyNameLabel(
    QLabel* company_name_label) {
  shifter_.ShiftWidget(ConversionFactor(0.5, 0.0), WidgetShifter::kShiftRight,
                       Geometry::CompanyNameLabel(), company_name_label);
}

void SplashScreenSizeComposer::ComposeSplashScreenLabels(QLabel* date_label,
                                                         QLabel* time_label,
                                                         QLabel* text_label) {
  shifter_.ShiftWidget(ConversionFactor(0.5, 1.0),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       Geometry::DateLabel(), date_label);
  shifter_.ShiftWidget(ConversionFactor(0.5, 1.0),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       Geometry::TimeLabel(), time_label);
  shifter_.ShiftWidget(ConversionFactor(0.5, 1.0),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       Geometry::TextLabel(), text_label);
}

void SplashScreenSizeComposer::ComposeAtmLabel(QLabel* atm_label) {
  atm_label_stretcher_.StretchAtmLabel(atm_label, delta_size_.Width(),
                                       delta_size_.Height());
}

void SplashScreenSizeComposer::ComputeDeltas(int extra_width,
                                             int extra_height) {
  delta_size_.SetWidth(extra_width - Geometry::InitialScreenWidth());
  delta_size_.SetHeight(extra_height - Geometry::InitialScreenHeight());
  shifter_.SetDeltaSize(delta_size_);
}

QRect SplashScreenSizeComposer::NewLabelGeometry(const QRect& label) {
  return QRect(label.x() + delta_size_.Width() / 2,
               label.y() + delta_size_.Height(), label.width(),
               label.height());
}
