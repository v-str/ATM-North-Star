#include <confirmation_frame.h>

std::string ConfirmationFrame::kText = "No text";
std::string ConfirmationFrame::kFrameSymbol = "#";

void ConfirmationFrame::SetFrame(const std::string& text,
                                 const std::string& frame_symbol) {
  kText = text;
  kFrameSymbol = frame_symbol;
}
