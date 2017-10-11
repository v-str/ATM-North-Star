#ifndef ATM_LABEL_STRETCHER_H
#define ATM_LABEL_STRETCHER_H

#include <QFont>

class QLabel;

class AtmLabelStretcher {
 public:
  void StretchAtmLabel(QLabel* atm_label, int width_increase,
                       int height_increase);

 private:
  void ComputeFontSize();
  void FitFrameByFontSize(const QLabel* atm_label);
  void PerformStretching(QLabel* atm_label);

  static const int kInitFontSize = 65;
  static const int kFontSizeLimit = 130;

  int font_pointsize_ = 0;
  int font_height_ = 0;

  int width_increase_ = 0;
  int height_increase_ = 0;

  QFont font_;
};

#endif  // ATM_LABEL_STRETCHER_H
