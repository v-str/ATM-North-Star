#ifndef DEMO_USER_MESSANGER_H
#define DEMO_USER_MESSANGER_H

#include "system_utility.h"

class DemoUserMessanger {
 public:
  void ShowWelcomeDemoMessage() const;

  void ShowDemoAccountInfoMessage() const;
  void ShowInfoAboutRefillMessage() const;
  void ShowDemoCreditAppMessage() const;
  void ShowDemoWidthdrawalMessage() const;
  void ShowDemoStatementMessage() const;
  void ShowDemoMenuMessage() const;

 private:
  void ShowDemoMenu() const;

  SystemUtility utility_;
};

#endif  // DEMO_USER_MESSANGER_H
