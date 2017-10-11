#include <splash_screen_geometry.h>

QRect SplashScreenGeometry::kVersionLabel = {5, 5, 100, 15};
QRect SplashScreenGeometry::kCompanyNameLabel = {45, 40, 490, 70};
QRect SplashScreenGeometry::kDateLabel = {215, 360, 160, 20};
QRect SplashScreenGeometry::kTimeLabel = {215, 330, 160, 20};
QRect SplashScreenGeometry::kTextLabel = {130, 295, 320, 30};
QRect SplashScreenGeometry::kSplashScreenFrame = {5, 30, 580, 355};
QRect SplashScreenGeometry::kAtmLabel = {130, 115, 320, 175};

QRect SplashScreenGeometry::VersionLabel() { return kVersionLabel; }

QRect SplashScreenGeometry::CompanyNameLabel() { return kCompanyNameLabel; }

QRect SplashScreenGeometry::DateLabel() { return kDateLabel; }

QRect SplashScreenGeometry::TimeLabel() { return kTimeLabel; }

QRect SplashScreenGeometry::TextLabel() { return kTextLabel; }

QRect SplashScreenGeometry::SplashScreenFrame() { return kSplashScreenFrame; }

QRect SplashScreenGeometry::AtmLabel() { return kAtmLabel; }
