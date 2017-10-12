#ifndef SPLASH_SCREEN_COMPOSER_H
#define SPLASH_SCREEN_COMPOSER_H

#include <atm_label_stretcher.h>

#include <geometry_composer.h>

class QLabel;
class QFrame;

class AtmSplashScreen;

class SplashScreenComposer {
 public:
  void TuneLabels(QLabel* version_label, QLabel* company_name_label,
                  QLabel* text_label, QLabel* atm_label);

  void ComposeFrame(QFrame* frame);
  void ComposeCompanyNameLabel(QLabel* company_name_label);
  void ComposeTextLabel(QLabel* text_label);
  void ComposeAtmLabel(QLabel* atm_label);

  void ComputeDeltas(int extra_width, int extra_height);

 private:
  AtmLabelStretcher atm_label_stretcher_;
  GeometryComposer composer_;
  DeltaSize delta_size_;
};

#endif  // SPLASH_SCREEN_COMPOSER_H
