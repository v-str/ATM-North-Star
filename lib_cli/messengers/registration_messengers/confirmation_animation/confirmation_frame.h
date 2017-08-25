#ifndef CONFIRMATION_FRAME_H
#define CONFIRMATION_FRAME_H

#include <string>

class ConfirmationFrame {
 public:
  static void SetFrame(const std::string& text,
                       const std::string& frame_symbol);

  static void DrawFrame(int loading_percent);

 private:
  static void DrawHorizontalLine();

  static std::string kText;
  static std::string kFrameSymbol;

  static const int kLineLength = 41;
};

#endif  // CONFIRMATION_FRAME_H
