#include <color_designer.h>

#include <QWidget>

ColorDesigner::ColorDesigner(QList<QWidget*> color_list)
    : color_list_(color_list),
      main_color_("black"),
      secondary_color_("grey"),
      additional_color_("blue") {}

ColorDesigner::~ColorDesigner() {}
