#include <initial_frame_geometry.h>

QRect InitialFrameGeometry::kInitialFrame = {5, 30, 580, 355};
QRect InitialFrameGeometry::kButtonFrame = {0, 0, 160, 200};
QRect InitialFrameGeometry::kSignInButton = {220, 112, 140, 40};
QRect InitialFrameGeometry::kRegistrationButton = {220, 162, 140, 40};
QRect InitialFrameGeometry::kDemoButton = {220, 212, 140, 40};

QRect InitialFrameGeometry::InitialFrame() { return kInitialFrame; }

QRect InitialFrameGeometry::ButtonFrame() { return kButtonFrame; }

QRect InitialFrameGeometry::SignInButton() { return kSignInButton; }

QRect InitialFrameGeometry::RegistrationButton() { return kRegistrationButton; }

QRect InitialFrameGeometry::DemoButton() { return kDemoButton; }

int InitialFrameGeometry::WidgetInterval() { return widget_interval_pt_; }
