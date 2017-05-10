#include "painter.h"

#include <QFrame>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QWidget>

void Painter::ChangeLabelColor(QLabel* label, const QString& text_color) {
  QString string_text_color =
      "QLabel{"
      "color: %1;"
      "border: 0px solid black;"
      "}";

  label->setStyleSheet(string_text_color.arg(text_color));
}

void Painter::ChangeButtonColor(QPushButton* push_button,
                                const QString& main_color,
                                const QString& secondary_color,
                                const QString& additional_color) {
  QString string_color =
      "QPushButton{"
      "color:%1;"
      "border-radius:5px;"
      "border:1px solid %1;"
      "}"
      "QPushButton:hover{"
      "border:1px solid %3;"
      "}"
      "QPushButton:pressed{"
      "color:%2;"
      "border:1px solid %2;"
      "}";

  push_button->setStyleSheet(
      string_color.arg(main_color, secondary_color, additional_color));
}

void Painter::ChangeFrameColor(QFrame* frame, const QString& color) {
  QString string_color =
      "QFrame{"
      "background:transparent;"
      "border: 1px solid %1;"
      "border-radius: 5px;"
      "}";

  frame->setStyleSheet(string_color.arg(color));
}

void Painter::ChangeBackgroundColor(QMainWindow* widget,
                                    const QString& background_color) {
  QString string_background_string =
      "QMainWindow{"
      "background: %1;"
      "}";

  widget->setStyleSheet(string_background_string.arg(background_color));
}

void Painter::ChangeBackgroundImage(QMainWindow* widget,
                                    const QString& background_image) {
  QString string_background_string =
      "QMainWindow{"
      "background-image: url(%1);"
      "}";

  widget->setStyleSheet(string_background_string.arg(background_image));
}
void Painter::ChangeBackgroundColor(QWidget* widget,
                                    const QString& background_color) {
  QString string_background_string =
      "QWidget{"
      "background: %1;"
      "}";

  widget->setStyleSheet(string_background_string.arg(background_color));
}

void Painter::ChangeBackgroundImage(QWidget* widget,
                                    const QString& background_image) {
  QString string_background_string =
      "QWidget{"
      "background-image: url(%1);"
      "}";

  widget->setStyleSheet(string_background_string.arg(background_image));
}
