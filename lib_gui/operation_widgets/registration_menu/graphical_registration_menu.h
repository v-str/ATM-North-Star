#ifndef GRAPHICAL_REGISTRATION_MENU_H
#define GRAPHICAL_REGISTRATION_MENU_H

#include <base_atm_frame.h>

#include <delta_size.h>
#include <registration_composer.h>

class GraphicalRegistrationMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit GraphicalRegistrationMenu(QWidget* parent = nullptr);
  ~GraphicalRegistrationMenu();

 public slots:
  void ChangeRegistrationMenuGeometry(const DeltaSize& delta_size);

 private:
  RegistrationComposer registration_composer_;

  static const int kHalfASecond = 500;
};

#endif  // GRAPHICAL_REGISTRATION_MENU_H
