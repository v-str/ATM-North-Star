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
  static std::stringstream conversion_stream_;
};

#endif  // USER_DATA_CONVERTER_H

template <typename T>
std::string UserDataConverter::ConvertDataToString(const T& value) {
  conversion_stream_.str("");
  conversion_stream_.clear();

  conversion_stream_ << std::fixed << std::setprecision(2) << value;

  return conversion_stream_.str();
}
