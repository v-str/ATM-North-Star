#ifndef REGISTRATION_REPORTER_H
#define REGISTRATION_REPORTER_H

#include <registration_status.h>

class RegistrationReporter {
 public:
  typedef CONSOLE::RegistrationStatus STATUS;

  void ShowLoginReport(STATUS login_status);
  void ShowPasswordReport(STATUS password_status);
};

#endif  // REGISTRATION_REPORTER_H
