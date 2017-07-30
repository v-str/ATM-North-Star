#ifndef REGISTRATION_MENU_H
#define REGISTRATION_MENU_H

#include <base_atm_frame.h>

#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class QWidget;
class AtmButton;
class OperationFrame;

class RegistrationMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit RegistrationMenu(QWidget* parent = nullptr);
  ~RegistrationMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;
};

#endif  // REGISTRATION_MENU_H
