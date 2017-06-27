#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QRect>

class Geometry {
 public:
  static QRect VersionLabel();
  static QRect CompanyNameLabel();

 private:
  static QRect kVersionLabel;
  static QRect kCompanyNameLabel;
};

#endif  // GEOMETRY_H
