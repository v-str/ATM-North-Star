#ifndef CHECK_STATE_H
#define CHECK_STATE_H

struct CheckState {
  static const int kAppropriateSumForCredit = 1000;
  static const int kNull = 0;
  static const int kPositiveCheck = 0;
  static const int kCreditExist = 1;
  static const int kInappropriateBalance = 2;
  static const int kInvalidCheck = -1;
  static const int kMaximalCreditTerm = 60;
};

#endif  // CHECK_STATE_H
