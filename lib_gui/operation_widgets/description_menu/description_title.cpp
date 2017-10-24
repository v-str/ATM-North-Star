#include <description_title.h>

#include <QFont>
#include <QList>
#include <QResizeEvent>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <description_menu_geometry.h>
#include <font_size_controller.h>

DescriptionTitle::DescriptionTitle(QWidget* parent)
    : QLabel(parent), font_size_controller_(new FontSizeController) {
  setGeometry(DescriptionMenuGeometry::DescriptionTitle());
  setAlignment(Qt::AlignCenter);
  ColorizeWidget();
}

DescriptionTitle::~DescriptionTitle() { delete font_size_controller_; }

void DescriptionTitle::resizeEvent(QResizeEvent* event) {
  font_size_controller_->ControlFontSize(11, 50, 10, event->size().width(),
                                         this);
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
