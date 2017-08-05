#ifndef DESCRIPTION_LABEL_H
#define DESCRIPTION_LABEL_H

#include <QLabel>

class QWidget;
class AtmColorDesigner;
class FontSizeController;

class DescriptionLabel : public QLabel {
  Q_OBJECT
 public:
  DescriptionLabel(QWidget* parent = nullptr);
  ~DescriptionLabel();

 public slots:
  void ShowAccountInfo();
  void ShowCashRefillInfo();
  void ShowCreditAppInfo();
  void ShowWithdrawalInfo();
  void ShowStatementInfo();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetDescriptionLabel();
  void ColorizeWidget();

  AtmColorDesigner* color_designer_ = nullptr;
  FontSizeController* font_size_controller_ = nullptr;

  static const int kInitialFontSize = 11;
  static const int kDivideFontSizeCoefficient = 50;
};

#endif  // DESCRIPTION_LABEL_H
