#include <atm_color_designer.h>

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QString>

#include <application_color.h>
#include <initial_menu_frame.h>
#include <painter.h>

AtmColorDesigner::AtmColorDesigner() {}

void AtmColorDesigner::SetBackgroundColor(QMainWindow* main_window) {
  Painter::ChangeBackgroundColor(
      main_window, ApplicationColor::ApplicationBackgroundColor());
}

void AtmColorDesigner::SetBackgroundColor(QDialog* dialog) {
  Painter::ChangeBackgroundColor(
      dialog, ApplicationColor::ApplicationBackgroundColor());
}

void AtmColorDesigner::PaintWidgetSet(QList<QLabel*> label_list) const {
  for (auto label = label_list.begin(); label != label_list.end(); ++label) {
    Painter::ChangeLabelColor(*label, ApplicationColor::MainColor());
  }
}

void AtmColorDesigner::PaintWidgetSet(QList<QPushButton*> button_list) const {
  for (auto button = button_list.begin(); button != button_list.end();
       ++button) {
    Painter::ChangeButtonColor(*button, ApplicationColor::MainColor(),
                               ApplicationColor::SecondaryColor(),
                               ApplicationColor::AdditionalColor());
  }
}

void AtmColorDesigner::PaintWidgetSet(QList<QFrame*> frame_list) const {
  for (auto frame = frame_list.begin(); frame != frame_list.end(); ++frame) {
    Painter::ChangeFrameColor(*frame, ApplicationColor::MainColor());
  }
}

void AtmColorDesigner::PaintInitialFrame(InitialMenuFrame* frame) const {
  QString string_color =
      "QFrame{"
      "background:transparent;"
      "border: 1px solid %1;"
      "border-radius: 5px;"
      "}";

  frame->setStyleSheet(string_color.arg(ApplicationColor::MainColor()));
}
