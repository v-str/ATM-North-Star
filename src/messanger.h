#ifndef MESSANGER_H
#define MESSANGER_H

#include "system_utility.h"

class Messanger {
 public:
  void ShowDemoMenu() const;
  void ShowWelcomeDemoMessage() const;

  void ShowDemoAccountInfoMsg() const;
  void ShowInfoAboutRefillMsg() const;
  void ShowDemoCreditAppMsg() const;
  void ShowDemoWidthdrawalMsg() const;
  void ShowDemoStatementMsg() const;
};

#endif  // DEMO_MESSANGER_H
