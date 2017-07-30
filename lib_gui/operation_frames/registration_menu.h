#ifndef REGISTRATION_MENU_H
#define REGISTRATION_MENU_H

#include <QFrame>
#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class QWidget;
class AtmButton;
class OperationFrame;

class RegistrationMenu : public QFrame {
  Q_OBJECT
 public:
  explicit RegistrationMenu(QWidget* parent = nullptr);
  ~RegistrationMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void SetInitialGeometry();
  void PaintWidgets();
  void SetFrameAnimation();

  AtmButton* back_button_ = nullptr;
  OperationFrame* operation_frame_ = nullptr;

  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;
};

#endif  // REGISTRATION_MENU_H
