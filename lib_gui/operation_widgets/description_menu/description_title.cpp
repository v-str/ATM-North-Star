#include <description_title.h>

#include <QFont>
#include <QList>
#include <QResizeEvent>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <description_menu_geometry.h>

DescriptionTitle::DescriptionTitle(QWidget* parent) : QLabel(parent) {
  setGeometry(DescriptionMenuGeometry::DescriptionTitle());
  setAlignment(Qt::AlignCenter);
  ColorizeWidget();
}

DescriptionTitle::~DescriptionTitle() {}

void DescriptionTitle::ColorizeWidget() {
  QString stylesheet_string =
      "DescriptionTitle {"
      "color: %1;"
      "border: 1px solid %2"
      "}";

  setStyleSheet(stylesheet_string.arg(ApplicationColor::MainColor(),
                                      ApplicationColor::MainColor()));
}
