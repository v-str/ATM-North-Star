#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <QFrame>
#include <QLabel>

#include <main_frame_composer.h>

class TimeLabel;
class DateLabel;

class MainFrame : public QFrame {
  Q_OBJECT

 public:
  MainFrame(QWidget* parent = nullptr);
  ~MainFrame();

 private:
  void InitializeLabels();
  void SetMainFrame();
  void PaintMainFrame();

  TimeLabel* time_label_ = nullptr;
  DateLabel* date_label_ = nullptr;

  MainFrameComposer main_frame_composer_;
};

#endif  // MAIN_FRAME_H
