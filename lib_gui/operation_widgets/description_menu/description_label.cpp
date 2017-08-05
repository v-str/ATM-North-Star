#include <description_label.h>

#include <application_color.h>
#include <atm_color_designer.h>
#include <description_menu_geometry.h>

DescriptionLabel::DescriptionLabel(QWidget* parent)
    : QLabel(parent), color_designer_(new AtmColorDesigner) {
  setGeometry(DescriptionMenuGeometry::DescriprionLabel());
  ColorizeWidget();
}

DescriptionLabel::~DescriptionLabel() {}

void DescriptionLabel::ColorizeWidget() {
  QString stylesheet_string =
      "DescriptionTitle {"
      "color: %1;"
      "border: 1px solid %2"
      "}";

  setStyleSheet(stylesheet_string.arg(ApplicationColor::MainColor(),
                                      ApplicationColor::MainColor()));
}
