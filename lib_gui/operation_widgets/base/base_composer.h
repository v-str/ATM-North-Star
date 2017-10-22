#ifndef BASE_COMPOSER_H
#define BASE_COMPOSER_H

#include <delta_size.h>
#include <geometry_composer.h>

class AtmButton;

class BaseComposer {
 public:
  BaseComposer();

  static void SetDeltaSize(const DeltaSize& delta_size);
  static void ComposeBackButton(AtmButton* back_button);

 private:
  static void SetBackButtonSettings();

  static GeometryComposer kBackButtonCompser;
  static DeltaSize kDeltaSize;
};

#endif  // BASE_COMPOSER_H
