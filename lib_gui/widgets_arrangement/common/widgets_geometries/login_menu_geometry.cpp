#include <login_menu_geometry.h>

QRect LoginMenuGeometry::kLoginFrame = {5, 30, 580, 355};
QRect LoginMenuGeometry::kBackButton = {5, 320, 50, 30};

QRect LoginMenuGeometry::LoginFrame() { return kLoginFrame; }

QRect LoginMenuGeometry::BackButton() { return kBackButton; }
