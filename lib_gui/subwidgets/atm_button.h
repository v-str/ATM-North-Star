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

  AtmButton(QWidget* widget = nullptr);
  AtmButton(const QString& text,
            unsigned int offset_side,
            QWidget* widget = nullptr);

  void SetOffsetSide(unsigned int offset_side);

  void SetXHoverOffset(int x_offset = 5);
  void SetYHoverOffset(int y_offset = 5);

  ~AtmButton();

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

 private:
  void OffsetButton();
  void ReturnToInitialPosition();

  int x_offset_ = 5;
  int y_offset_ = 5;

  unsigned int offset_side_;

  bool is_focus_ = false;
};

#endif  // ATM_BUTTON_H
