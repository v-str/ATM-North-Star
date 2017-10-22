#ifndef INITIAL_MENU_COMPOSER_H
#define INITIAL_MENU_COMPOSER_H

#include <delta_size.h>
#include <geometry_composer.h>

class QWidget;

class InitialMenuComposer {
 public:
  InitialMenuComposer();

  void ComposeMenu(const DeltaSize& delta_size, QWidget* initial_menu);
  void ComposeFrame(const DeltaSize& delta_size, QWidget* frame);

 private:
  void SetDefaultMenuComposingSettings();
  void SetDefaultFrameComposingSettings();

  GeometryComposer frame_composer_;
  GeometryComposer menu_composer_;

  static constexpr double kXFrameFactor = 0.5;
  static constexpr double kYFrameFactor = 0.5;

  static constexpr double kXMenuFactor = 1.0;
  static constexpr double kYMenuFactor = 1.0;
};

#endif  // INITIAL_MENU_COMPOSER_H
