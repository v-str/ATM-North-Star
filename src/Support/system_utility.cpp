#include "system_utility.h"

#include <chrono>
#include <iostream>
#include <thread>

void SystemUtility::Sleep(int latency_ms) const {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}

void SystemUtility::ClearScreen() const { system("clear"); }
