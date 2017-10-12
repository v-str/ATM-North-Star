#include <main_widget_composer.h>

#include <initial_frame_geometry.h>
#include <main_widget_geometry.h>
#include <side.h>
#include <splash_screen_geometry.h>
#include <widget_font.h>

MainWidgetComposer::MainWidgetComposer() { SetDefaultComposing(); }

void MainWidgetComposer::ComposeMainFrame(QFrame* main_frame) {
  menu_composer_.ComposeGeometry(MainWidgetGeometry::MainFrame(), main_frame);
}

void MainWidgetComposer::ComposeMenu(QWidget* widget) {
  menu_composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(), widget);
}

void MainWidgetComposer::ComposeSplashScreen(QWidget* widget) {
  menu_composer_.ComposeGeometry(SplashScreenGeometry::SplashScreenFrame(),
                                 widget);
}

void MainWidgetComposer::ComposeTimeAndDate(QLabel* time_label,
                                            QLabel* date_label) {
  time_label->setGeometry(MainWidgetGeometry::TimeLabel());
  time_label->setFont(WidgetFont::SetFont(12));
  time_label->setAlignment(Qt::AlignRight);

  date_label->setGeometry(MainWidgetGeometry::DateLabel());
  date_label->setFont(WidgetFont::SetFont(12));
  date_label->setAlignment(Qt::AlignRight);

  label_composer_.SetShiftFactor(kXFactor, kYFactor);
  label_composer_.SetShiftSide(Side::kRight);
  label_composer_.SetTransformationType(GeometryComposer::kShift);

  label_composer_.ComposeGeometry(MainWidgetGeometry::TimeLabel(), time_label);
  label_composer_.ComposeGeometry(MainWidgetGeometry::DateLabel(), date_label);
}

void MainWidgetComposer::SetDeltaSize(const DeltaSize& delta_size) {
  menu_composer_.SetDeltaSize(delta_size);
  label_composer_.SetDeltaSize(delta_size);
}

void MainWidgetComposer::SetDefaultComposing() {
  menu_composer_.SetStretchFactor(kXFactor, kYFactor);
  menu_composer_.SetStretchSide(Side::kRight | Side::kDown);
  menu_composer_.SetTransformationType(GeometryComposer::kStretch);
}
