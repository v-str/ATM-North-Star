#include <atm_checkbox.h>

#include <atm_color_designer.h>
#include <registration_menu_geometry.h>
#include <widget_font.h>

AtmCheckbox::AtmCheckbox(QWidget* parent)
    : QCheckBox("I'm familiarized", parent) {
  setFont(WidgetFont::SetFont(14));
  AtmColorDesigner::PaintSingleWidget(this);
}

AtmCheckbox::~AtmCheckbox() {}
