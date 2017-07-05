#include <initial_geometry.h>

QPoint InitialGeometry::kVersionLabel = {485, 17};
QPoint InitialGeometry::kCompanyNameLabel = {35, 40};
QPoint InitialGeometry::kDateLabel = {140, 360};
QPoint InitialGeometry::kTimeLabel = {300, 360};
QPoint InitialGeometry::kTextLabel = {150, 270};
QRect InitialGeometry::kSplashScreenFrame = {10, 10, 580, 380};

QRect InitialGeometry::kSignInButton = {220, 112, 140, 40};
QRect InitialGeometry::kRegistrationButton = {220, 162, 140, 40};
QRect InitialGeometry::kDemoButton = {220, 212, 140, 40};

int InitialGeometry::InitialScreenWidth() { return kInitialScreenWidth; }

int InitialGeometry::InitialScreenHeight() { return kInitialScreenHeight; }

QPoint InitialGeometry::VersionLabel() { return kVersionLabel; }

QPoint InitialGeometry::CompanyNameLabel() { return kCompanyNameLabel; }

QPoint InitialGeometry::DateLabel() { return kDateLabel; }

QPoint InitialGeometry::TimeLabel() { return kTimeLabel; }

QPoint InitialGeometry::TextLabel() { return kTextLabel; }

QRect InitialGeometry::SplashScreenFrame() { return kSplashScreenFrame; }

QRect InitialGeometry::SignInButton() { return kSignInButton; }

QRect InitialGeometry::RegistrationButton() { return kRegistrationButton; }

QRect InitialGeometry::DemoButton() { return kDemoButton; }
