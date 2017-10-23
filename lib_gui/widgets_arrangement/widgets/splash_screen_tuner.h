#ifndef SPLASH_SCREEN_TUNER_H
#define SPLASH_SCREEN_TUNER_H

#include <atm_label_stretcher.h>
#include <delta_size.h>

class QLabel;
class QFrame;

class SplashScreenTuner {
 public:
  static void TuneLabels(QLabel* version_label,
                         QLabel* company_name_label,
                         QLabel* text_label,
                         QLabel* atm_label);

  static void StretchAtmLabel(const DeltaSize& delta_size, QLabel* atm_label);

 private:
  static void SetText(QLabel* version_label,
                      QLabel* text_label,
                      QLabel* atm_label);
  static void SetGeometry(QLabel* version_label, QLabel* company_name_label);
  static void SetFont(QLabel* version_label,
                      QLabel* company_name_label,
                      QLabel* text_label,
                      QLabel* atm_label);
  static void SetAlignment(QLabel* company_name_label,
                           QLabel* text_label,
                           QLabel* atm_label);

  static AtmLabelStretcher kAtmLabelStretcher;
};

#endif  // SPLASH_SCREEN_TUNER_H
