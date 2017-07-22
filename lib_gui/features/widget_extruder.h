#ifndef WIDGET_EXTRUDER_H
#define WIDGET_EXTRUDER_H

#include <QObject>

class QPropertyAnimation;
class QWidget;
class QRect;

class WidgetExtruder : public QObject {
  Q_OBJECT
 public:
  ~WidgetExtruder();
};

#endif  // WIDGET_EXTRUDER_H
