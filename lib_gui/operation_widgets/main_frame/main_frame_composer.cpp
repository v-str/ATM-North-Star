#include <main_frame_composer.h>

#include <main_frame_geometry.h>

void MainFrameComposer::SetMainFrame(QFrame *main_frame, QLabel *time_label,
                                     QLabel *date_label) {
  main_frame->setGeometry(MainFrameGeometry::MainFrame());
  time_label->setGeometry(MainFrameGeometry::TimeLabel());
  date_label->setGeometry(MainFrameGeometry::DateLabel());
}

void MainFrameComposer::PaintMainFrame(QFrame *main_frame, QLabel *time_label,
                                       QLabel *date_label) {
  color_designer_.PaintFrame(main_frame);
  color_designer_.PaintSingleWidget(time_label);
  color_designer_.PaintSingleWidget(date_label);
}
