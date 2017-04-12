#ifndef CHECK_STATE_H
#define CHECK_STATE_H

struct CheckState {
  const int kAppropriateSumForCredit = 1000;
  const int kNull = 0;
  const int kPositiveCheck = 0;
  const int kCreditExist = 1;
  const int kInappropriateBalance = 2;
  const int kInvalidCheck = -1;
  const int kMaximalCreditTerm = 60;
};

#endif  // CHECK_STATE_H
