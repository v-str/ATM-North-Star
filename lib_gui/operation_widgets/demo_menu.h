#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <base_atm_frame.h>

#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class DemoMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit DemoMenu(QWidget* parent = nullptr);
  ~DemoMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  QFrame* demo_button_frame_ = nullptr;

  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;

  static const int kHalfASecond = 500;
};

#endif  // DEMO_MENU_H
