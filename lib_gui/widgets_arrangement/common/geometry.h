#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry {
 public:
  static int InitialScreenWidth();
  static int InitialScreenHeight();

 private:
  static const int kInitialScreenWidth = 600;
  static const int kInitialScreenHeight = 400;
};

#endif  // GEOMETRY_H
