#ifndef MAIN_WIDGET_COMPOSER_H
#define MAIN_WIDGET_COMPOSER_H

#include <QFrame>
#include <QLabel>
#include <QWidget>

#include <atm_color_designer.h>
#include <delta_size.h>
#include <geometry_composer.h>

class MainWidgetComposer {
 public:
  MainWidgetComposer();

  void ComposeMainFrame(QFrame* main_frame);
  void ComposeMenu(QWidget* widget);
  void ComposeSplashScreen(QWidget* widget);
  void ComposeTimeAndDate(QLabel* time_label, QLabel* date_label);
  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  void SetDefaultComposing();

  GeometryComposer menu_composer_;
  GeometryComposer label_composer_;

  AtmColorDesigner color_designer_;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;
};

#endif  // MAIN_WIDGET_COMPOSER_H
