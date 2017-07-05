#ifndef ATM_BUTTON_H
#define ATM_BUTTON_H

#include <QPushButton>

class QRect;

class QString;
class QWidget;

class AtmButton : public QPushButton {
  Q_OBJECT
 public:
  enum OffsetSide { kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

  AtmButton(QWidget* widget = nullptr);
  AtmButton(const QString& text,
            unsigned int offset_side,
            QWidget* widget = nullptr);

  ~AtmButton();

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

 private:
  void OffsetButton();
  void ReturnToInitialPosition();

  static const int offset_ = 7;

  unsigned int offset_side_;

  bool is_focus_ = false;
};

#endif  // ATM_BUTTON_H
