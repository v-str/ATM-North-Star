#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <delta_size.h>
#include <geometry_composer.h>

#include <QFrame>

class QWidget;
class AtmColorDesigner;
class AtmButton;

class DemoMenu : public QFrame {
  Q_OBJECT
 public:
  DemoMenu(QWidget* parent = nullptr);
  ~DemoMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void SetInitialGeometry();
  void PaintWidgets();

  void SetScalingProperties();

  AtmColorDesigner* color_designer_ = nullptr;
  AtmButton* back_button_ = nullptr;

  GeometryComposer composer_;
  DeltaSize delta_size_;
};

#endif  // DEMO_MENU_H
