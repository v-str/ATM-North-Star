#ifndef DESCRIPTION_LABEL_H
#define DESCRIPTION_LABEL_H

#include <QLabel>

class QWidget;
class AtmColorDesigner;

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

 private:
  void ColorizeWidget();

  AtmColorDesigner* color_designer_ = nullptr;
};

#endif  // DESCRIPTION_LABEL_H
