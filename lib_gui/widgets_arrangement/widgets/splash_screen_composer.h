#ifndef SPLASH_SCREEN_COMPOSER_H
#define SPLASH_SCREEN_COMPOSER_H

#include <QRect>

#include <atm_label_stretcher.h>

#include <delta_size.h>
#include <geometry_composer.h>

class QPushButton;
class QLabel;
class QFrame;

class AtmSplashScreen;

class SplashScreenComposer {
 public:
  void TuneLabels(QLabel* version_label, QLabel* company_name_label,
                  QLabel* text_label, QLabel* atm_label);

  void SetFrame(QFrame* frame);
  void SetCompanyNameLabel(QLabel* company_name_label);
  void SetTextLabel(QLabel* text_label);
  void SetAtmLabel(QLabel* atm_label);

  void ComputeDeltas(int extra_width, int extra_height);

 private:
  QRect NewLabelGeometry(const QRect& label);

  static const int kAtmLabelFontSize = 100;

  AtmLabelStretcher atm_label_stretcher_;
  GeometryComposer composer_;
  DeltaSize delta_size_;
};

#endif  // SPLASH_SCREEN_COMPOSER_H
