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

void DescriptionTitle::resizeEvent(QResizeEvent* event) {
  int grows_coefficient = event->size().width() / kDivideFontCoefficient;
  int font_size = kInitialFontSize + grows_coefficient;

  QFont new_font = font();
  new_font.setPointSize(font_size);

  setFont(new_font);
}

void DescriptionTitle::ColorizeWidget() {
  QString stylesheet_string =
      "DescriptionTitle {"
      "color: %1;"
      "border: 1px solid %2"
      "}";

  setStyleSheet(stylesheet_string.arg(ApplicationColor::MainColor(),
                                      ApplicationColor::MainColor()));
}
