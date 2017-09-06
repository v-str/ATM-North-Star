#ifndef DESCRIPTION_FRAME_H
#define DESCRIPTION_FRAME_H

#include <QFrame>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class AtmColorDesigner;
class AtmButton;
class QVBoxLayout;

class DescriptionFrame : public QFrame {
  Q_OBJECT
 public:
  DescriptionFrame(QWidget* parent = nullptr);
  ~DescriptionFrame();

  void SetDeltaSize(const DeltaSize& delta_size);

 public slots:
  void ProcessAccountInfoButton();
  void ProcessCashRefillButton();
  void ProcessCreditAppButton();
  void ProcessCashWithdrawalButton();
  void ProcessStatementButton();

 signals:
  void AccountInfoButtonClicked();
  void CashRefillButtonClicked();
  void CreditAppButtonClicked();
  void CashWithdrawalButtonClicked();
  void StatementButtonClicked();

 private:
  void RemoveButtonsVisualOffset();
  void SetGridLayout();
  void SetGeometries();
  void ColorizeWidgets();

  void SetConnections();

  AtmColorDesigner* color_designer_ = nullptr;

  AtmButton* account_info_button_ = nullptr;
  AtmButton* cash_refill_button_ = nullptr;
  AtmButton* credit_app_button_ = nullptr;
  AtmButton* cash_withdrawal_button_ = nullptr;
  AtmButton* statement_button_ = nullptr;

  QVBoxLayout* layout_ = nullptr;

  DeltaSize delta_size_;
};

#endif  // DESCRIPTION_FRAME_H
