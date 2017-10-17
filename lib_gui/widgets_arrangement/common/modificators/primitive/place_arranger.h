#ifndef PLACE_ARRANGER_H
#define PLACE_ARRANGER_H

#include <QWidget>

class PlaceArranger {
 public:
  static void PlaceAtTheFirstMonitor(QWidget* widget);

  static void PlaceToCenterRelativelyOf(QWidget* move_widget,
                                        const QRect& rectangle);

 private:
  static int FirstScreenWidth();
  static int HalfOf(int length);
};

#endif  // PLACE_ARRANGER_H
