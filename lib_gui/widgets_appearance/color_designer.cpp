#include <color_designer.h>

#include <QWidget>

ColorDesigner::ColorDesigner(QList<QWidget*> color_list)
    : color_list_(color_list),
      main_color_("black"),
      secondary_color_("grey"),
      additional_color_("blue") {}

void ColorDesigner::SetWidgetPalette(const QString& main_color,
                                     const QString& secondary_color,
                                     const QString& additional_color) {
  main_color_ = main_color;
  secondary_color_ = secondary_color;
  additional_color_ = additional_color;
}

ColorDesigner::~ColorDesigner() {}

QList<QWidget*> ColorDesigner::ColorList() { return color_list_; }

QString ColorDesigner::MainColor() { return main_color_; }

QString ColorDesigner::SecondaryColor() { return secondary_color_; }

QString ColorDesigner::AdditionalColor() { return additional_color_; }
