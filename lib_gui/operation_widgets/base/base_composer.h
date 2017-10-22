#ifndef BASE_COMPOSER_H
#define BASE_COMPOSER_H

#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>

class AtmButton;
class QWidget;

class BaseComposer {
 public:
  BaseComposer();

  static void SetDeltaSize(const DeltaSize& delta_size);
  static void ComposeBackButton(AtmButton* back_button);
  static void ComposeWidget(const QRect& widget_geometry, QWidget* widget);

 private:
  static void SetBackButtonSettings();

  static GeometryComposer kBackButtonComposer;
  static DeltaSize kDeltaSize;
};

#endif  // BASE_COMPOSER_H
