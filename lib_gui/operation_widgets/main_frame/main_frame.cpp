#include <main_frame.h>

#include <QResizeEvent>

#include <atm_composer.h>
#include <date_label.h>
#include <main_frame_geometry.h>
#include <time_label.h>

MainFrame::MainFrame(QWidget* parent) : QFrame(parent) {
  InitializeLabels();
  SetMainFrame();
  PaintMainFrame();
}

MainFrame::~MainFrame() {}

void MainFrame::ChangeGeometry() {
  AtmComposer::StretchWidget(MainFrameGeometry::MainFrame(),
                             Side::kRight | Side::kDown, 1.0, 1.0, this);
  AtmComposer::ShiftWidget(MainFrameGeometry::TimeLabel(), Side::kRight, 1.0,
                           1.0, time_label_);
  AtmComposer::ShiftWidget(MainFrameGeometry::DateLabel(), Side::kRight, 1.0,
                           1.0, date_label_);
}

void MainFrame::InitializeLabels() {
  time_label_ = new TimeLabel(this);
  date_label_ = new DateLabel(this);
}

void MainFrame::SetMainFrame() {
  main_frame_composer_.SetMainFrameAppearance(this, time_label_, date_label_);
}

void MainFrame::PaintMainFrame() {
  main_frame_composer_.PaintMainFrame(this, time_label_, date_label_);
}
