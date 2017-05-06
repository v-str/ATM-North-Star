#include "text_color_changer.h"

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QString>

void TextColorChanger::ChangeLabelColor(QLabel* label,
                                        const QString& text_color) {
  QString string_text_color =
      "QLabel{"
      "color: %1;"
      "border: 0px solid black;"
      "}";

  label->setStyleSheet(string_text_color.arg(text_color));
}

void TextColorChanger::ChangeButtonColor(QPushButton* push_button,
                                         const QString& main_color,
                                         const QString& additional_color) {
  QString string_color =
      "QPushButton{"
      "color:%1;"
      "border-radius:5px;"
      "}"
      "QPushButton:hover{"
      "border:1px solid %1;"
      "}"
      "QPushButton:pressed{"
      "color:%2;"
      "border:1px solid %2;"
      "}";

  push_button->setStyleSheet(string_color.arg(main_color, additional_color));
}

void TextColorChanger::ChangeFrameColor(QFrame* frame, const QString& color) {
  QString string_color =
      "QFrame{"
      "background:transparent;"
      "border: 1px solid %1;"
      "border-radius: 5px;"
      "}";

  frame->setStyleSheet(string_color.arg(color));
}
