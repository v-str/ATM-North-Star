#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <delta_size.h>

#include <QFrame>

class QWidget;
class AtmColorDesigner;

class DemoMenu : public QFrame {
  Q_OBJECT
 public:
  DemoMenu(QWidget* parent = nullptr);
  ~DemoMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  AtmColorDesigner* color_designer_ = nullptr;

  DeltaSize delta_size_;
};

#endif  // DEMO_MENU_H
