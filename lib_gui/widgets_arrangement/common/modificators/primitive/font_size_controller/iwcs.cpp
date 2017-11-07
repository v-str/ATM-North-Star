#include <iwcs.h>

double IWCS::kWidthMultiplier = 1.5;

void IWCS::SetIww(int iww) { iww_ = iww; }

void IWCS::SetIwh(int iwh) { iwh_ = iwh; }

void IWCS::SetIfh(int ifh) {
  ifh_ = ifh;
  SetIfch();
  SetIfcw();
}

void IWCS::SetIfps(int ifps) { ifps_ = ifps; }

void IWCS::SetIfch() { ifch_ = iwh_ / ifps_; }

void IWCS::SetIfcw() { ifcw_ = kWidthMultiplier * ifch_; }

int IWCS::Iww() const { return iww_; }

int IWCS::Iwh() const { return iwh_; }

int IWCS::Ifh() const { return ifh_; }

int IWCS::Ifps() const { return ifps_; }

int IWCS::Ifch() const { return ifch_; }

int IWCS::Ifcw() const { return ifcw_; }
