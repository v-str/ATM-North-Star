#ifndef CONFIRMATION_FRAME_H
#define CONFIRMATION_FRAME_H

#include <string>

class ConfirmationFrame {
 public:
  static void SetFrame(const std::string& login_string,
                       const std::string& frame_symbol);

  static void DrawFrame(int loading_percent);

 private:
  static void DrawHorizontalLine();
  static void DrawEmptyLine();
  static void DrawTextLine();
  static void DrawLoginLine();

  static void DrawString(const std::string& string);

  static std::string kLoginString;
  static std::string kFrameSymbol;

  static const int kLineLength = 41;
};

#endif  // CONFIRMATION_FRAME_H
