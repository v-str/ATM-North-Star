#ifndef USER_DATA_CONVERTER_H
#define USER_DATA_CONVERTER_H

#include <iomanip>
#include <sstream>
#include <string>

class UserDataConverter {
 public:
  template <typename T>
  static std::string ConvertDataToString(const T& value);

 private:
  std::stringstream conversion_stream_;
};

#endif  // USER_DATA_CONVERTER_H

template <typename T>
std::string UserDataConverter::ConvertDataToString(
    const UserDataConverter::T& value) {
  conversion_stream_.clear();

  conversion_stream_ << std::fixed << std::setprecision(2)
                     << std::to_string(value);

  return conversion_stream_.str();
}
