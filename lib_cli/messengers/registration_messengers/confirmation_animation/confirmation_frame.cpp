#include <confirmation_frame.h>

std::string confirmation_frame::kText = "No text";
std::string confirmation_frame::kFrameSymbol = "#";

void confirmation_frame::SetFrame(const std::string& text,
                                  const std::string& frame_symbol) {
  kText = text;
  kFrameSymbol = frame_symbol;
}
