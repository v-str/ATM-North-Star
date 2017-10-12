#include <main_frame_composer.h>

#include <delta_size.h>
#include <main_frame_geometry.h>
#include <side.h>
#include <widget_font.h>

MainFrameComposer::MainFrameComposer() { SetDefaultComposing(); }

void MainFrameComposer::SetMainFrameAppearance(QFrame *main_frame,
                                               QLabel *time_label,
                                               QLabel *date_label) {
  main_frame->setGeometry(MainFrameGeometry::MainFrame());
  SetTime(time_label);
  SetDate(date_label);
}

void MainFrameComposer::PaintMainFrame(QFrame *main_frame, QLabel *time_label,
                                       QLabel *date_label) {
  color_designer_.PaintFrame(main_frame);
  color_designer_.PaintSingleWidget(time_label);
  color_designer_.PaintSingleWidget(date_label);
}

void MainFrameComposer::ComposeLabels(QLabel *time_label, QLabel *date_label) {
  composer_.ComposeGeometry(MainFrameGeometry::TimeLabel(), time_label);
  composer_.ComposeGeometry(MainFrameGeometry::DateLabel(), date_label);
}

void MainFrameComposer::SetDeltaSize(int delta_width, int delta_height) {
  composer_.SetDeltaSize(DeltaSize(delta_width, delta_height));
}

MainFrameComposer::SetDefaultComposing() {
  composer_.SetShiftFactor(kXFactor, kYFactor);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kShift);
}

void MainFrameComposer::SetTime(QLabel *time_label) {
  time_label->setGeometry(MainFrameGeometry::TimeLabel());
  time_label->setFont(WidgetFont::SetFont(12));
  time_label->setAlignment(Qt::AlignRight);
}

void MainFrameComposer::SetDate(QLabel *date_label) {
  date_label->setGeometry(MainFrameGeometry::DateLabel());
  date_label->setFont(WidgetFont::SetFont(12));
  date_label->setAlignment(Qt::AlignRight);
}
