#ifndef APP_GEOMETRY_H
#define APP_GEOMETRY_H

class AppGeometry {
 public:
  static int InitialWidth();
  static int InitialHeight();

 private:
  static const int kInitialWidth = 600;
  static const int kInitialHeight = 400;
};

#endif  // APP_GEOMETRY_H
