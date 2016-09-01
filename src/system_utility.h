#ifndef SYSTEM_UTILITY_H
#define SYSTEM_UTILITY_H

#include <string>

using string = std::string;

void Sleep(int latency_ms);
void WriteTextWithDelay(const string &text);
void IgnoreCinLine();
void ClearScreen();

void ShowDemoMenu();
void ShowWelcomeDemoMessage();

#endif  // SYSTEM_UTILITY_H
