#include <splash_screen_composer.h>

#include <QFont>
#include <QFrame>
#include <QLabel>
#include <QPoint>

#include <geometry.h>

void SplashScreenSizeComposer::ComposeFrame(QFrame* frame) {
  frame->setGeometry(
      Geometry::SplashScreenFrame().x(), Geometry::SplashScreenFrame().y(),
      Geometry::SplashScreenFrame().width() + delta_size_.DeltaWidth(),
      Geometry::SplashScreenFrame().height() + delta_size_.DeltaHeight());
}

void SplashScreenSizeComposer::ComposeVersionLabel(QLabel* version_label) {
  shifter_.ShiftWidget(1.0, WidgetShifter::kShiftRight,
                       Geometry::VersionLabel(), version_label);
}

void SplashScreenSizeComposer::ComposeCompanyNameLabel(
    QLabel* company_name_label) {
  shifter_.ShiftWidget(0.5, WidgetShifter::kShiftRight,
                       Geometry::CompanyNameLabel(), company_name_label);
}

void SplashScreenSizeComposer::ComposeSplashScreenLabels(QLabel* date_label,
                                                         QLabel* time_label,
                                                         QLabel* text_label) {
  date_label->setGeometry(NewLabelGeometry(Geometry::DateLabel()));
  time_label->setGeometry(NewLabelGeometry(Geometry::TimeLabel()));
  text_label->setGeometry(NewLabelGeometry(Geometry::TextLabel()));
}

void SplashScreenSizeComposer::ComposeAtmLabel(QLabel* atm_label) {
  atm_label_stretcher_.StretchAtmLabel(atm_label, delta_size_.DeltaWidth(),
                                       delta_size_.DeltaHeight());
}

void SplashScreenSizeComposer::ComputeDeltas(int extra_width,
                                             int extra_height) {
  delta_size_.SetDeltaWidth(extra_width - Geometry::InitialScreenWidth());
  delta_size_.SetDeltaHeight(extra_height - Geometry::InitialScreenHeight());
  shifter_.SetDeltaSize(delta_size_);
}

QRect SplashScreenSizeComposer::NewLabelGeometry(const QRect& label) {
  return QRect(label.x() + delta_size_.DeltaWidth() / 2,
               label.y() + delta_size_.DeltaHeight(), label.width(),
               label.height());
}
