#include <splash_screen_geometry.h>

QRect SplashScreenGeometry::kVersionLabel = {485, 17, 100, 15};
QRect SplashScreenGeometry::kCompanyNameLabel = {40, 40, 510, 70};
QRect SplashScreenGeometry::kDateLabel = {215, 360, 160, 20};
QRect SplashScreenGeometry::kTimeLabel = {215, 330, 160, 20};
QRect SplashScreenGeometry::kTextLabel = {135, 270, 320, 30};
QRect SplashScreenGeometry::kSplashScreenFrame = {5, 5, 590, 390};
QRect SplashScreenGeometry::kAtmLabel = {105, 115, 300, 150};

QRect SplashScreenGeometry::VersionLabel() { return kVersionLabel; }

QRect SplashScreenGeometry::CompanyNameLabel() { return kCompanyNameLabel; }

QRect SplashScreenGeometry::DateLabel() { return kDateLabel; }

QRect SplashScreenGeometry::TimeLabel() { return kTimeLabel; }

QRect SplashScreenGeometry::TextLabel() { return kTextLabel; }

QRect SplashScreenGeometry::SplashScreenFrame() { return kSplashScreenFrame; }

QRect SplashScreenGeometry::AtmLabel() { return kAtmLabel; }
