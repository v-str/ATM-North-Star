#ifndef DESCRIPTION_LABEL_H
#define DESCRIPTION_LABEL_H

#include <QLabel>

class QWidget;
class TextAnimation;

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

 signals:
  void StartAnimation();

 private:
  void SetDescriptionLabel();
  void ColorizeWidget();

  TextAnimation* text_animation_ = nullptr;

  static const int kDelayMSec = 5;
};

#endif  // DESCRIPTION_LABEL_H
