#include <painter.h>

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QString>

#include <application_color.h>

void Painter::ChangeLabelColor(QLabel* label, const QString& text_color) {
  QString string_text_color =
      "QLabel{"
      "color: %1;"
      "border: 1px solid %1;"
      "}";

  label->setStyleSheet(string_text_color.arg(text_color));
}

void Painter::ChangeButtonColor(QPushButton* push_button) {
  QString string_color =
      "QPushButton{"
      "color:%1;"
      "border-radius:5px;"
      "border:1px solid %1;"
      "}"
      "QPushButton:hover{"
      "border:1px solid %3;"
      "}"
      "QPushButton:focus{"
      "background-color:%4;"
      "}"
      "QPushButton:pressed{"
      "color:%2;"
      "border:1px solid %2;"
      "}";

  push_button->setStyleSheet(string_color.arg(
      ApplicationColor::MainColor(), ApplicationColor::SecondaryColor(),
      ApplicationColor::AdditionalColor(),
      ApplicationColor::CheckedBackgroundColor()));
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

void Painter::ChangeBackground(QMainWindow* widget,
                               const QString& background_color) {
  QString string_background_string =
      "QMainWindow{"
      "background: %1;"
      "}";

  widget->setStyleSheet(string_background_string.arg(background_color));
}

void Painter::ChangeBackground(QDialog* widget,
                               const QString& background_color) {
  QString string_background_string =
      "QDialog{"
      "background: %1;"
      "}";

  widget->setStyleSheet(string_background_string.arg(background_color));
}
