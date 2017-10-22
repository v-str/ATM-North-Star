#include <back_button_property.h>

QRect BackButtonProperty::kBackButtonGeometry = {5, 320, 50, 30};

QRect BackButtonProperty::BackButtonGeometry() { return kBackButtonGeometry; }

double BackButtonProperty::XShift() { return kXShift; }

double BackButtonProperty::YShift() { return kYShift; }

double BackButtonProperty::XStretch() { return kXStretch; }

double BackButtonProperty::YStretch() { return kYStretch; }
