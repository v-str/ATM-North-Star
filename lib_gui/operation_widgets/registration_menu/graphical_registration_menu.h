#ifndef GRAPHICAL_REGISTRATION_MENU_H
#define GRAPHICAL_REGISTRATION_MENU_H

#include <base_atm_frame.h>

#include <delta_size.h>
#include <registration_composer.h>

class RegistrationDescription;

class GraphicalRegistrationMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit GraphicalRegistrationMenu(QWidget* parent = nullptr);
  ~GraphicalRegistrationMenu();

 public slots:
  void ChangeGeometry(const DeltaSize& delta_size) override;

 private:
  void SetConnections();

  RegistrationDescription* registration_description_ = nullptr;

  RegistrationComposer registration_composer_;
  DeltaSize operation_frame_delta_size_;

  static const int kHalfASecond = 500;
};

#endif  // GRAPHICAL_REGISTRATION_MENU_H
