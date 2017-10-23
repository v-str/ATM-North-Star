#ifndef GRAPHICAL_LOGIN_MENU_H
#define GRAPHICAL_LOGIN_MENU_H

#include <base_atm_frame.h>

class GraphicalLoginMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit GraphicalLoginMenu(QWidget* parent = nullptr);
  ~GraphicalLoginMenu();

 public slots:
  void ChangeGeometry() override;

 private:
};

#endif  // GRAPHICAL_LOGIN_MENU_H
