#ifndef MAIN_FRAME_COMPOSER_H
#define MAIN_FRAME_COMPOSER_H

#include <QFrame>
#include <QLabel>

#include <atm_color_designer.h>
#include <geometry_composer.h>

class MainFrameComposer {
 public:
  MainFrameComposer();

  void SetMainFrameAppearance(QFrame* main_frame,
                              QLabel* time_label,
                              QLabel* date_label);
  void PaintMainFrame(QFrame* main_frame,
                      QLabel* time_label,
                      QLabel* date_label);

  void ComposeLabels(QLabel* time_label, QLabel* date_label);

  void SetDeltaSize(int delta_width, int delta_height);

 private:
  void SetDefaultComposing();

  void SetTime(QLabel* time_label);
  void SetDate(QLabel* date_label);

  AtmColorDesigner color_designer_;
  GeometryComposer composer_;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;
};

#endif  // MAIN_FRAME_COMPOSER_H
