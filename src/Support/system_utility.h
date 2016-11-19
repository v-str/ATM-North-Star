#ifndef SYSTEM_UTILITY_H
#define SYSTEM_UTILITY_H

#include <string>

class SystemUtility {
  using string = std::string;

 public:
  void Sleep(int latency_ms) const;
  void ClearScreen() const;
};

#endif  // SYSTEM_UTILITY_H
