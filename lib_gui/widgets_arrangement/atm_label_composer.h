#ifndef ATM_LABEL_COMPOSER_H
#define ATM_LABEL_COMPOSER_H

class QLabel;

class AtmLabelComposer {
 public:
  void ComposeLabel(QLabel* atm_label,
                    int main_widget_width,
                    int main_widget_height);

  void ComputeFontSize(int main_widget_width, int main_widget_height);

 private:
  static const int kInitXPos = 140;
  static const int kInitYPos = 100;
  static const int kInitWidth = 300;
  static const int kInitHeight = 150;
  static const int kInitFontSize = 100;
  static const int kFontSizeLimit = 170;

  int final_font_size_ = 0;
};

#endif  // ATM_LABEL_COMPOSER_H
