#ifndef CONFIRMATION_FRAME_H
#define CONFIRMATION_FRAME_H

#include <string>

class confirmation_frame {
 public:
  static void SetFrame(const std::string& text,
                       const std::string& frame_symbol);

 private:
  static std::string kText;
  static std::string kFrameSymbol;
};

#endif  // CONFIRMATION_FRAME_H
