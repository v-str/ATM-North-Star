#include <size_screen_controller.h>

#include <QMainWindow>

bool SizeScreenController::is_full_screen_ = false;

void SizeScreenController::SetFullScreen(QMainWindow* widget) {
  widget->showFullScreen();
  is_full_screen_ = true;
}

void SizeScreenController::SetNormalScreen(QMainWindow* widget) {
  widget->showNormal();
  is_full_screen_ = false;
}

bool SizeScreenController::IsFullScreen() { return is_full_screen_; }
