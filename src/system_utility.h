#ifndef SYSTEM_UTILITY_H
#define SYSTEM_UTILITY_H

#include <string>

using string = std::string;

void Sleep(int latency_ms);
void IgnoreCinLine();
void ClearScreen();
void WriteTextWithDelay(const string &text, int delay = 5);

#endif  // SYSTEM_UTILITY_H
