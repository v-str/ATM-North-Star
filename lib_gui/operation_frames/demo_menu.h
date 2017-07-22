#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <QFrame>

class QWidget;
class AtmColorDesigner;

class DemoMenu : public QFrame {
  Q_OBJECT
 public:
  DemoMenu(QWidget* parent = nullptr);
  ~DemoMenu();

 private:
  AtmColorDesigner* color_designer_ = nullptr;
};

#endif  // DEMO_MENU_H
