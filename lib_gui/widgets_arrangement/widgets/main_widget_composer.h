#ifndef MAIN_WIDGET_COMPOSER_H
#define MAIN_WIDGET_COMPOSER_H

#include <QFrame>
#include <QWidget>

#include <delta_size.h>
#include <geometry_composer.h>

class MainWidgetComposer {
 public:
  MainWidgetComposer();

  void SetMainFrame(QFrame* main_frame);
  void ComposeMenu(QWidget* widget);
  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  void SetDefaultComposing();

  GeometryComposer composer_;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;
};

#endif  // MAIN_WIDGET_COMPOSER_H
