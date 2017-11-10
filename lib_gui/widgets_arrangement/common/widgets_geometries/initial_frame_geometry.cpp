#include <initial_frame_geometry.h>

QRect InitialFrameGeometry::kInitialFrame = {5, 30, 580, 355};
QRect InitialFrameGeometry::kButtonFrame = {200, 117, 180, 100};
QRect InitialFrameGeometry::kLoginButton = {220, 117, 140, 40};
QRect InitialFrameGeometry::kRegistrationButton = {220, 167, 140, 40};
QRect InitialFrameGeometry::kDemoButton = {220, 212, 140, 40};

QRect InitialFrameGeometry::InitialFrame() { return kInitialFrame; }

QRect InitialFrameGeometry::ButtonFrame() { return kButtonFrame; }

QRect InitialFrameGeometry::LoginButton() { return kLoginButton; }

QRect InitialFrameGeometry::RegistrationButton() { return kRegistrationButton; }

QRect InitialFrameGeometry::DemoButton() { return kDemoButton; }
