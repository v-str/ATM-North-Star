#ifndef GROUP_BORDER_CONTROLLER_H
#define GROUP_BORDER_CONTROLLER_H

#include <border_controller.h>

class GroupBorderController : public BorderController {
 public:
  enum GroupMode { kVertical, kHorizontal };

  void SetGroupMode(GroupMode group_mode);

 private:
  GroupMode group_mode_;
};

#endif  // GROUP_BORDER_CONTROLLER_H
