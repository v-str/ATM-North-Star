#include "system_utility.h"

#include <chrono>
#include <thread>

void Sleep(int latency_ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(latency_ms));
}
