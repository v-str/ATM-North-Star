#ifndef DESCRIPTION_TEXT_H
#define DESCRIPTION_TEXT_H

#include <QString>

class DescriptionText {
 public:
  static QString AccountInfoText();
  static QString CashRefillInfoText();
  static QString CreditAppText();
  static QString WithdrawalInfoText();
  static QString StatementIndoText();

 private:
  static QString kAccountInfo;
  static QString kCashRefill;
  static QString kCreditApp;
  static QString kWithdrawal;
  static QString kStatement;
};

#endif  // DESCRIPTION_TEXT_H
