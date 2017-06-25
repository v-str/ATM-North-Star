#include <atm_color_designer.h>

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QString>

#include <painter.h>
#include <widget_color.h>

AtmColorDesigner::AtmColorDesigner() {}

void AtmColorDesigner::SetBackgroundColor(QMainWindow* main_window,
                                          const QString& background_color) {
  Painter::ChangeBackgroundColor(main_window, background_color);
}

void AtmColorDesigner::SetBackgroundColor(QDialog* dialog,
                                          const QString& background_color) {
  Painter::ChangeBackgroundColor(dialog, background_color);
}

void AtmColorDesigner::PaintWidgetSet(QList<QLabel*> label_list) const {
  for (auto label = label_list.begin(); label != label_list.end(); ++label) {
    Painter::ChangeLabelColor(*label, WidgetColor::MainColor());
  }
}

void AtmColorDesigner::PaintWidgetSet(QList<QPushButton*> button_list) const {
  for (auto button = button_list.begin(); button != button_list.end();
       ++button) {
    Painter::ChangeButtonColor(*button, WidgetColor::MainColor(),
                               WidgetColor::SecondaryColor(),
                               WidgetColor::AdditionalColor());
  }
}

void AtmColorDesigner::PaintWidgetSet(QList<QFrame*> frame_list) const {
  for (auto frame = frame_list.begin(); frame != frame_list.end(); ++frame) {
    Painter::ChangeFrameColor(*frame, WidgetColor::MainColor());
  }
}
