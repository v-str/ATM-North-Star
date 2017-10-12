#include <atm_color_designer.h>

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>

#include <application_color.h>
#include <painter.h>

AtmColorDesigner::AtmColorDesigner() {}

void AtmColorDesigner::SetBackground(QMainWindow* main_window) {
  Painter::ChangeBackground(main_window,
                            ApplicationColor::ApplicationBackgroundColor());
}

void AtmColorDesigner::SetBackground(QDialog* dialog) {
  Painter::ChangeBackground(dialog,
                            ApplicationColor::ApplicationBackgroundColor());
}

void AtmColorDesigner::PaintWidgetSet(QList<QLabel*>* label_list) const {
  for (auto label = label_list->begin(); label != label_list->end(); ++label) {
    Painter::ChangeLabelColor(*label, ApplicationColor::MainColor());
  }
}

void AtmColorDesigner::PaintWidgetSet(QList<QPushButton*>* button_list) const {
  for (auto button = button_list->begin(); button != button_list->end();
       ++button) {
    Painter::ChangeButtonColor(*button);
  }
}

void AtmColorDesigner::PaintWidgetSet(QList<QFrame*>* frame_list) const {
  for (auto frame = frame_list->begin(); frame != frame_list->end(); ++frame) {
    Painter::ChangeFrameColor(*frame, ApplicationColor::MainColor());
  }
}

void AtmColorDesigner::PaintSingleWidget(QLabel* label) const {
  Painter::ChangeLabelColor(label, ApplicationColor::MainColor());
}

void AtmColorDesigner::PaintSingleWidget(QPushButton* button) const {
  Painter::ChangeButtonColor(button);
}

void AtmColorDesigner::PaintSingleWidget(QFrame* frame) const {
  Painter::ChangeFrameColor(frame, ApplicationColor::MainColor());
}

void AtmColorDesigner::PaintFrame(QFrame* frame) const {
  QString string_color =
      "QFrame{"
      "background:transparent;"
      "border: 1px solid %1;"
      "border-radius: 5px;"
      "}";

  frame->setStyleSheet(string_color.arg(ApplicationColor::MainColor()));
}
