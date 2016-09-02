#ifndef DEMO_USER_MESSANGER_H
#define DEMO_USER_MESSANGER_H

#include "system_utility.h"

class DemoUserMessanger {
 public:
  void ShowDemoMenu() const;
  void ShowWelcomeDemoMessage() const;

  void ShowDemoAccountInfoMessage() const;
  void ShowInfoAboutRefillMessage() const;
  void ShowDemoCreditAppMessage() const;
  void ShowDemoWidthdrawalMessage() const;
  void ShowDemoStatementMessage() const;
};

#endif  // DEMO_USER_MESSANGER_H
