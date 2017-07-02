#include <geometry.h>

QPoint Geometry::kVersionLabel = {485, 17};
QRect Geometry::kCompanyNameLabel = {35, 40, 510, 70};
QRect Geometry::kDateLabel = {140, 360, 160, 20};
QRect Geometry::kTimeLabel = {300, 360, 160, 20};
QRect Geometry::kTextLabel = {150, 270, 280, 30};
QRect Geometry::kSplashScreenFrame = {10, 10, 580, 380};

int Geometry::InitialScreenWidth() { return kInitialScreenWidth; }

int Geometry::InitialScreenHeight() { return kInitialScreenHeight; }

QPoint Geometry::VersionLabel() { return kVersionLabel; }

QRect Geometry::CompanyNameLabel() { return kCompanyNameLabel; }

QRect Geometry::DateLabel() { return kDateLabel; }

QRect Geometry::TimeLabel() { return kTimeLabel; }

QRect Geometry::TextLabel() { return kTextLabel; }

QRect Geometry::SplashScreenFrame() { return kSplashScreenFrame; }
