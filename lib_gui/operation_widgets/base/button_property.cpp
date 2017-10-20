#include <button_property.h>

double ButtonProperty::kButtonStretchX = 0.7;
double ButtonProperty::kButtonStretchY = 0.3;
double ButtonProperty::kButtonShiftX = 0.0;
double ButtonProperty::kButtonShiftY = 1.0;

double ButtonProperty::StretchX() const { return kButtonStretchX; }

double ButtonProperty::StretchY() const { return kButtonStretchY; }

double ButtonProperty::ShiftX() const { return kButtonShiftX; }

double ButtonProperty::ShiftY() const { return kButtonShiftY; }
