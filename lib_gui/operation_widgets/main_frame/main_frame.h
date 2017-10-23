#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <QFrame>
#include <QLabel>

#include <atm_color_designer.h>

class TimeLabel;
class DateLabel;

class MainFrame : public QFrame {
  Q_OBJECT

 public:
  MainFrame(QWidget* parent = nullptr);
  ~MainFrame();

 public slots:
  void ChangeGeometry();

 private:
  void InitializeLabels();
  void SetMainFrame();
  void PaintMainFrame();

  TimeLabel* time_label_ = nullptr;
  DateLabel* date_label_ = nullptr;

  AtmColorDesigner color_designer_;
};

#endif  // MAIN_FRAME_H
