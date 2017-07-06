#include <initial_geometry.h>

QRect InitialGeometry::kVersionLabel = {485, 17, 100, 15};
QRect InitialGeometry::kCompanyNameLabel = {35, 40, 510, 70};
QRect InitialGeometry::kDateLabel = {140, 360, 160, 20};
QRect InitialGeometry::kTimeLabel = {300, 360, 160, 20};
QRect InitialGeometry::kTextLabel = {150, 270, 280, 30};
QRect InitialGeometry::kSplashScreenFrame = {10, 10, 580, 380};

QRect InitialGeometry::kSignInButton = {220, 112, 140, 40};
QRect InitialGeometry::kRegistrationButton = {220, 162, 140, 40};
QRect InitialGeometry::kDemoButton = {220, 212, 140, 40};

int InitialGeometry::InitialScreenWidth() { return kInitialScreenWidth; }

int InitialGeometry::InitialScreenHeight() { return kInitialScreenHeight; }

QRect InitialGeometry::VersionLabel() { return kVersionLabel; }

QRect InitialGeometry::CompanyNameLabel() { return kCompanyNameLabel; }

QRect InitialGeometry::DateLabel() { return kDateLabel; }

QRect InitialGeometry::TimeLabel() { return kTimeLabel; }

QRect InitialGeometry::TextLabel() { return kTextLabel; }

QRect InitialGeometry::SplashScreenFrame() { return kSplashScreenFrame; }

QRect InitialGeometry::SignInButton() { return kSignInButton; }

QRect InitialGeometry::RegistrationButton() { return kRegistrationButton; }

QRect InitialGeometry::DemoButton() { return kDemoButton; }
