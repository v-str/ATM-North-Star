#ifndef GRAPHICAL_LOGIN_MENU_H
#define GRAPHICAL_LOGIN_MENU_H

#include <base_atm_frame.h>

#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class GraphicalLoginMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit GraphicalLoginMenu(QWidget* parent = nullptr);
  ~GraphicalLoginMenu();

 public slots:
  void ChangeLoginMenuGeometry(const DeltaSize& delta_size);

 private:
  GeometryComposer composer_;
  WidgetBorderController border_controller_;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;

  static const int kHalfASecond = 500;
};

#endif  // GRAPHICAL_LOGIN_MENU_H
