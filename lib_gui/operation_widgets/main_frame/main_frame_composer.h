#ifndef MAIN_FRAME_COMPOSER_H
#define MAIN_FRAME_COMPOSER_H

#include <QFrame>
#include <QLabel>

#include <atm_color_designer.h>

class MainFrameComposer {
 public:
  MainFrameComposer();

  void SetMainFrameAppearance(QFrame* main_frame,
                              QLabel* time_label,
                              QLabel* date_label);
  void PaintMainFrame(QFrame* main_frame,
                      QLabel* time_label,
                      QLabel* date_label);

 private:
  void SetTime(QLabel* time_label);
  void SetDate(QLabel* date_label);

  AtmColorDesigner color_designer_;
};

#endif  // MAIN_FRAME_COMPOSER_H
