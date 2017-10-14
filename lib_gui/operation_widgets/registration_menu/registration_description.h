#ifndef REGISTRATION_DESCRIPTION_H
#define REGISTRATION_DESCRIPTION_H

#include <base_atm_frame.h>

class QWidget;

class RegistrationDescription : public BaseAtmFrame {
 public:
  explicit RegistrationDescription(QWidget* parent = nullptr);
  ~RegistrationDescription();
};

#endif  // REGISTRATION_DESCRIPTION_H
