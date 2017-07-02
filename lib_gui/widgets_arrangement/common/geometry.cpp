#include <geometry.h>

QPoint Geometry::kVersionLabel = {485, 17};
QPoint Geometry::kCompanyNameLabel = {35, 40};
QPoint Geometry::kDateLabel = {140, 360};
QPoint Geometry::kTimeLabel = {300, 360};
QPoint Geometry::kTextLabel = {150, 270};
QRect Geometry::kSplashScreenFrame = {10, 10, 580, 380};

int Geometry::InitialScreenWidth() { return kInitialScreenWidth; }

int Geometry::InitialScreenHeight() { return kInitialScreenHeight; }

QPoint Geometry::VersionLabel() { return kVersionLabel; }

QPoint Geometry::CompanyNameLabel() { return kCompanyNameLabel; }

QPoint Geometry::DateLabel() { return kDateLabel; }

QPoint Geometry::TimeLabel() { return kTimeLabel; }

QPoint Geometry::TextLabel() { return kTextLabel; }

QRect Geometry::SplashScreenFrame() { return kSplashScreenFrame; }
