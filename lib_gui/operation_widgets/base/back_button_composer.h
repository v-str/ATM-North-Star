#ifndef BACK_BUTTON_COMPOSER_H
#define BACK_BUTTON_COMPOSER_H

#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>

class AtmButton;

class BackButtonComposer {
 public:
  static void ComposeBackButton(const DeltaSize& delta_size,
                                AtmButton* back_button);

  static DeltaSize GetBackButtonDeltaSize();

 private:
  static void SetBackButtonSettings();

  static GeometryComposer kBackButtonComposer;
  static QRect kCurrentBackButtonGeometry;
  static DeltaSize kDeltaSize;
};

#endif  // BACK_BUTTON_COMPOSER_H
