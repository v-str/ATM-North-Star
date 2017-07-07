#include <initial_frame_geometry.h>

QRect InitialFrameGeometry::kSignInButton = {220, 112, 140, 40};
QRect InitialFrameGeometry::kRegistrationButton = {220, 162, 140, 40};
QRect InitialFrameGeometry::kDemoButton = {220, 212, 140, 40};

QRect InitialFrameGeometry::SignInButton() { return kSignInButton; }

QRect InitialFrameGeometry::RegistrationButton() { return kRegistrationButton; }

QRect InitialFrameGeometry::DemoButton() { return kDemoButton; }
