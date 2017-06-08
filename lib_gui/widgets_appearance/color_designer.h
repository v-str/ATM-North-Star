#ifndef COLOR_DESIGNER_H
#define COLOR_DESIGNER_H

#include <QList>
#include <QString>

class QWidget;

class ColorDesigner {
 public:
  ColorDesigner(QList<QWidget*> color_list);
  virtual ~ColorDesigner() = 0;

  void SetWidgetPalette(const QString& main_color,
                        const QString& secondary_color,
                        const QString& additional_color);

  virtual void PaintWidgets() = 0;

 private:
  QList<QWidget*> color_list_;
  QString main_color_;
  QString secondary_color_;
  QString additional_color_;
};

#endif  // COLOR_DESIGNER_H
