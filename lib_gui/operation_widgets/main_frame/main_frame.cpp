#include <main_frame.h>

#include <date_label.h>
#include <main_widget_geometry.h>
#include <time_label.h>

MainFrame::MainFrame(QWidget* parent) : QFrame(parent) {
  InitializeLabels();
  SetMainFrame();
}

MainFrame::~MainFrame() {
  delete time_label_;
  delete date_label_;
}

void MainFrame::InitializeLabels() {
  time_label_ = new TimeLabel(qobject_cast<QLabel*>(this));
  date_label_ = new DateLabel(qobject_cast<QLabel*>(this));
}

void MainFrame::SetMainFrame() {
  main_frame_composer_.SetInitialSettings(this, time_label_, date_label_);
}
