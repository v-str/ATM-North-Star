#ifndef APP_GEOMETRY_H
#define APP_GEOMETRY_H

class AppGeometry {
 public:
  static int InitialScreenWidth();
  static int InitialScreenHeight();

 private:
  static const int kInitialScreenWidth = 600;
  static const int kInitialScreenHeight = 400;
};

#endif  // APP_GEOMETRY_H
