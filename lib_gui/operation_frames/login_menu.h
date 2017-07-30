#ifndef LOGIN_MENU_H
#define LOGIN_MENU_H

#include <base_atm_frame.h>

#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class LoginMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit LoginMenu(QWidget* parent = nullptr);
  ~LoginMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;
};

#endif  // LOGIN_MENU_H
