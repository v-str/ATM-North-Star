#ifndef BASE_ATM_COMPOSER_H
#define BASE_ATM_COMPOSER_H

#include <QRect>
#include <QWidget>

#include <atm_button.h>
#include <delta_size.h>
#include <geometry_composer.h>

class BaseAtmComposer {
 public:
  BaseAtmComposer();

  void SetDeltaSize(const DeltaSize& delta_size);
  void ComposeFrame(const QRect& frame_geometry, QWidget* widget);
  void ComposeBackButton(const QRect& button_geometry, QWidget* widget);

  void SetFrameGeometry(const QRect& frame_geometry);
  void SetButtonGeometry(const QRect& button_geometry);

 private:
  void SetFrameComposer();
  void SetButtonComposer();

  GeometryComposer frame_composer_;
  GeometryComposer button_composer_;

  QRect frame_geometry_;
  QRect button_geometry_;
};

#endif  // BASE_ATM_COMPOSER_H
