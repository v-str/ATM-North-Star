#include <iwcs.h>

double IWCS::kWidthMultiplier = 1.5;

void IWCS::SetIww(int iww) { iww_ = iww; }

void IWCS::SetIwh(int iwh) { iwh_ = iwh; }

void IWCS::SetIfps(int ifps) {
  ifps_ = ifps;
  SetIfch();
  SetIfcw();
}

void IWCS::SetIfch() { ifch_ = iwh_ / ifps_; }

void IWCS::SetIfcw() { ifcw_ = kWidthMultiplier * ifch_; }

int IWCS::Iww() const { return iww_; }

int IWCS::Iwh() const { return iwh_; }

int IWCS::Ifps() const { return ifps_; }

int IWCS::Ifch() const { return ifch_; }

int IWCS::Ifcw() const { return ifcw_; }
