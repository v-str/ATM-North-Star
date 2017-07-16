#ifndef ATM_BUTTON_H
#define ATM_BUTTON_H

#include <QPushButton>

class QRect;

class QString;
class QWidget;

class AtmButton : public QPushButton {
  Q_OBJECT
 public:
  enum OffsetSide { kNone = 0, kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

  AtmButton(const QString& text, QWidget* widget = nullptr);

  void SetOffsetSide(unsigned int offset_side);

  void SetXHoverOffset(int x_offset = 5);
  void SetYHoverOffset(int y_offset = 5);

  void SetDivideCoefficient(unsigned int divide_coefficient);

  ~AtmButton();

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);
  void resizeEvent(QResizeEvent* event);

 private:
  void OffsetButton();
  void ReturnToInitialPosition();

  int x_offset_ = 5;
  int y_offset_ = 5;

  unsigned int offset_side_ = 0;
  unsigned int grows_coefficient_ = 0;
  unsigned int divide_coefficient_ = 40;

  bool is_focus_ = false;

  static const int kInitialFontSize = 11;
};

#endif  // ATM_BUTTON_H
