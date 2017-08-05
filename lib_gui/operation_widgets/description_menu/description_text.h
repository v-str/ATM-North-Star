#ifndef DESCRIPTION_TEXT_H
#define DESCRIPTION_TEXT_H

#include <QString>

class DescriptionText {
 public:
  QString AccountInfoText();
  QString CashRefillInfoText();
  QString CreditAppText();
  QString WithdrawalInfoText();
  QString StatementIndoText();

 private:
  static QString kAccountInfo;
  static QString kCashRefill;
  static QString kCreditApp;
  static QString kWithdrawal;
  static QString kStatement;
};

#endif  // DESCRIPTION_TEXT_H
