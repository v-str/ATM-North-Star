#include <exit_dialog_geometry.h>

QRect ExitDialogGeometry::kExitDialog = {0, 0, 300, 150};
QRect ExitDialogGeometry::kExitDialogFrame = {5, 5, 290, 140};
QRect ExitDialogGeometry::kButtonYes = {40, 90, 100, 30};
QRect ExitDialogGeometry::kButtonNo = {150, 90, 100, 30};
QRect ExitDialogGeometry::kMessageScreen = {5, 5, 280, 70};

QRect ExitDialogGeometry::ExitDialog() { return kExitDialog; }

QRect ExitDialogGeometry::ExitDialogFrame() { return kExitDialogFrame; }

QRect ExitDialogGeometry::ButtonYes() { return kButtonYes; }

QRect ExitDialogGeometry::ButtonNo() { return kButtonNo; }

QRect ExitDialogGeometry::MessageScreen() { return kMessageScreen; }
