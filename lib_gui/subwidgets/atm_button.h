#ifndef ATM_BUTTON_H
#define ATM_BUTTON_H

#include <QPushButton>

#include <font_size_controller.h>

class QRect;
class QString;
class QWidget;
class QFont;

class AtmButton : public QPushButton {
  Q_OBJECT
 public:
  enum OffsetSide { kNone = 0, kLeft = 1, kRight = 2, kUp = 4, kDown = 8 };

  AtmButton(const QString& text, QWidget* widget = nullptr);

  void SetFont(const QFont& font);

  void SetOffsetSide(unsigned int offset_side);

  void SetXHoverOffset(int x_offset = 5);
  void SetYHoverOffset(int y_offset = 5);

  ~AtmButton();

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);
  void resizeEvent(QResizeEvent* event);

 private:
  void SetSizePolicy();
  void OffsetButton();
  void ReturnToInitialPosition();

  static const int KFontScaleCoefficient = 60;

  FontSizeController size_controller;

  int x_offset_ = 5;
  int y_offset_ = 5;
  unsigned int offset_side_ = 0;
  unsigned int font_size_pt_ = 0;

  bool is_focus_ = false;
};

#endif  // ATM_BUTTON_H
