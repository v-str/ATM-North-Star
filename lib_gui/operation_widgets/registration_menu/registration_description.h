#ifndef REGISTRATION_DESCRIPTION_H
#define REGISTRATION_DESCRIPTION_H

#include <base_atm_frame.h>

class QWidget;
class QRect;

class RegistrationDescription : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit RegistrationDescription(QWidget* parent = nullptr);
  ~RegistrationDescription();

 public slots:
  void ControlIndentation(const QRect& control_geometry);

 private:
  static const int kIndent = 10;
};

#endif  // REGISTRATION_DESCRIPTION_H
