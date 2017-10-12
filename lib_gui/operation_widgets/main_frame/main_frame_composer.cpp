#include <main_frame_composer.h>

#include <main_frame_geometry.h>

void MainFrameComposer::SetMainFrame(QFrame *main_frame, QLabel *time_label,
                                     QLabel *date_label) {
  main_frame->setGeometry(MainFrameGeometry::MainFrame());
  time_label->setGeometry(MainFrameGeometry::TimeLabel());
  date_label->setGeometry(MainFrameGeometry::DateLabel());
}
