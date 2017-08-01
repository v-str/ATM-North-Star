#ifndef DESCRIPTION_MENU_H
#define DESCRIPTION_MENU_H

#include <base_atm_frame.h>

#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class DescriptionMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit DescriptionMenu(QWidget* parent = nullptr);
  ~DescriptionMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  QFrame* button_frame_ = nullptr;

  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;

  static const int kHalfASecond = 500;
};

#endif  // DESCRIPTION_MENU_H
