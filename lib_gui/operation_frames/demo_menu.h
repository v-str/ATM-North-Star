#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <QFrame>

class QWidget;

class DemoMenu : public QFrame {
  Q_OBJECT
 public:
  DemoMenu(QWidget* parent = nullptr);
  ~DemoMenu();
};

#endif  // DEMO_MENU_H
