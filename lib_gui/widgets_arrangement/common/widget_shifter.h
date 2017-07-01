#ifndef WIDGET_SHIFTER_H
#define WIDGET_SHIFTER_H

#include <QPoint>
#include <QRect>

#include <delta_size.h>

class QLabel;
class QPushButton;

class WidgetShifter {
 public:
  enum ShiftDirection {
    kNone = 0,
    kShiftLeft = 1,
    kShiftRight = 2,
    kShiftUp = 4,
    kShiftDown = 8
  };

  void SetDeltaSize(const DeltaSize& delta_size);
  void SetMainWidgetPosition(const QRect& main_widget_position);

  void ShiftLabel(double shift_coefficient,
                  unsigned int direction_flag,
                  const QRect& initial_label_geometry,
                  QLabel* label);

  void ShiftButton(double shift_coefficient,
                   unsigned int direction_flag,
                   const QRect& initial_button_geometry,
                   QPushButton* button);

 private:
  void ResetShiftPosition();
  void SetShifting(unsigned int direction_flag, const QRect& initial_geometry);
  void AssignShiftCoefficient(double shift_coefficient);

  void MakeShifting(QLabel* label);
  void MakeShifting(QPushButton* button);

  bool IsMainWidgetBorderCrossed() const;

  DeltaSize delta_size_;
  QRect shift_position_;
  QRect main_widget_position_;

  double shift_coefficient_ = 0.0;
};

#endif  // WIDGET_SHIFTER_H
