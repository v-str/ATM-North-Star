#include <main_frame.h>

#include <QResizeEvent>

#include <atm_color_designer.h>
#include <atm_composer.h>
#include <date_label.h>
#include <main_frame_geometry.h>
#include <time_label.h>
#include <widget_font.h>

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
  setGeometry(MainFrameGeometry::MainFrame());

  time_label_->setGeometry(MainFrameGeometry::TimeLabel());
  time_label_->setFont(WidgetFont::SetFont(12));
  time_label_->setAlignment(Qt::AlignRight);

  date_label_->setGeometry(MainFrameGeometry::DateLabel());
  date_label_->setFont(WidgetFont::SetFont(12));
  date_label_->setAlignment(Qt::AlignRight);
}

void MainFrame::PaintMainFrame() {
  AtmColorDesigner::PaintFrame(this);
  AtmColorDesigner::PaintSingleWidget(time_label_);
  AtmColorDesigner::PaintSingleWidget(date_label_);
}
