#include <main_frame.h>

#include <QResizeEvent>

#include <date_label.h>
#include <main_frame_geometry.h>
#include <time_label.h>

MainFrame::MainFrame(QWidget* parent) : QFrame(parent) {
  InitializeLabels();
  SetMainFrame();
  PaintMainFrame();
}

MainFrame::~MainFrame() {}

void MainFrame::SetDeltaSize(const DeltaSize& delta_size) {
  main_frame_composer_.SetDeltaSize(delta_size);
}

void MainFrame::resizeEvent(QResizeEvent*) {
  main_frame_composer_.ComposeLabels(time_label_, date_label_);
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
