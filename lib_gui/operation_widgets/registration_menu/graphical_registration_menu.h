#ifndef GRAPHICAL_REGISTRATION_MENU_H
#define GRAPHICAL_REGISTRATION_MENU_H

#include <base_atm_frame.h>

class RegistrationDescription;
class AtmButton;

class GraphicalRegistrationMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit GraphicalRegistrationMenu(QWidget* parent = nullptr);
  ~GraphicalRegistrationMenu();

 public slots:
  void ChangeGeometry() override;

 private:
  void SetNextButton();
  void CalculateNextButtonGeometry();
  void SetConnections();

  RegistrationDescription* registration_description_ = nullptr;
  AtmButton* next_button_ = nullptr;
};

#endif  // GRAPHICAL_REGISTRATION_MENU_H
