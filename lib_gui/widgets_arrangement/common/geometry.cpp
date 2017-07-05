#include <geometry.h>

QPoint Geometry::kVersionLabel = {485, 17};
QPoint Geometry::kCompanyNameLabel = {35, 40};
QPoint Geometry::kDateLabel = {140, 360};
QPoint Geometry::kTimeLabel = {300, 360};
QPoint Geometry::kTextLabel = {150, 270};
QRect Geometry::kSplashScreenFrame = {10, 10, 580, 380};

QRect Geometry::kSignInButton = {220, 112, 140, 40};
QRect Geometry::kRegistrationButton = {220, 162, 140, 40};
QRect Geometry::kDemoButton = {220, 212, 140, 40};

int Geometry::InitialScreenWidth() { return kInitialScreenWidth; }

int Geometry::InitialScreenHeight() { return kInitialScreenHeight; }

QPoint Geometry::VersionLabel() { return kVersionLabel; }

QPoint Geometry::CompanyNameLabel() { return kCompanyNameLabel; }

QPoint Geometry::DateLabel() { return kDateLabel; }

QPoint Geometry::TimeLabel() { return kTimeLabel; }

QPoint Geometry::TextLabel() { return kTextLabel; }

QRect Geometry::SplashScreenFrame() { return kSplashScreenFrame; }

QRect Geometry::SignInButton() { return kSignInButton; }

QRect Geometry::RegistrationButton() { return kRegistrationButton; }

QRect Geometry::DemoButton() { return kDemoButton; }
