#ifndef NOTICE_MESSENGER_H
#define NOTICE_MESSENGER_H

#include <iostream>
#include "system_utility.h"

using std::cout;

class NoticeMessenger {
 public:
  void ShowFrame() const;

 private:
  SystemUtility utility_;
};

#endif  // NOTICE_MESSENGER_H
