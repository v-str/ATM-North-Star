#ifndef ATM_COMPOSER_H
#define ATM_COMPOSER_H

#include <QRect>

#include <back_button_composer.h>
#include <delta_size.h>
#include <geometry_composer.h>

class AtmButton;
class QWidget;

class AtmComposer {
 public:
  static void SetDeltaSize(const DeltaSize& delta_size);
  static void ComposeBackButton(AtmButton* back_button);
  static void ComposeWidget(const QRect& widget_geometry, QWidget* widget);

 private:
  static void SetBackButtonSettings();

  static BackButtonComposer kBackButtonComposer;
  static DeltaSize kDeltaSize;
};

#endif  // ATM_COMPOSER_H
