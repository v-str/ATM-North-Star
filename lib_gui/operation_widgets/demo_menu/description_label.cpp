#include <description_label.h>

#include <atm_color_designer.h>
#include <description_menu_geometry.h>

DescriptionLabel::DescriptionLabel(QWidget* parent)
    : QLabel(parent), color_designer_(new AtmColorDesigner) {
  setGeometry(DescriptionMenuGeometry::DescriprionLabel());
  setStyleSheet(
      "DescriptionLabel {"
      "border: 1px solid green;"
      "}");
}

DescriptionLabel::~DescriptionLabel() {}
