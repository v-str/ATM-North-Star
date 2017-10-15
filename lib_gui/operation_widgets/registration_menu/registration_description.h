#ifndef REGISTRATION_DESCRIPTION_H
#define REGISTRATION_DESCRIPTION_H

#include <base_atm_frame.h>

#include <atm_color_designer.h>

class QWidget;
class QRect;

class RegistrationDescription : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit RegistrationDescription(QWidget* parent = nullptr);
  ~RegistrationDescription();

 private:
  AtmColorDesigner color_designer_;

  static const int kHalfASecond = 500;
};

#endif  // REGISTRATION_DESCRIPTION_H
