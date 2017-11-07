#include <iwcs.h>

void IWCS::SetIww(int iww) { iww_ = iww; }

void IWCS::SetIwh(int iwh) { iwh_ = iwh; }

void IWCS::SetIfh(int ifh) { ifh_ = ifh; }

void IWCS::SetIfps(int ifps) { ifps_ = ifps; }

void IWCS::SetIfch(int ifch) { ifch_ = ifch; }

void IWCS::SetIfcw(int ifcw) { ifcw_ = ifcw; }

int IWCS::GetIww() const { return iww_; }

int IWCS::GetIwh() const { return iwh_; }

int IWCS::GetIfh() const { return ifh_; }

int IWCS::GetIfps() const { return ifps_; }

int IWCS::GetIfch() const { return ifch_; }

int IWCS::GetIfcw() const { return ifcw_; }
