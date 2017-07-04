#ifndef ATM_BUTTON_H
#define ATM_BUTTON_H

#include <QPushButton>

class QRect;

class QString;
class QWidget;

class AtmButton : public QPushButton {
  Q_OBJECT
 public:
  AtmButton(QWidget* widget = nullptr);
  AtmButton(const QString& text, QWidget* widget = nullptr);

  ~AtmButton();

 protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

 private:
  void OffsetButton();
  void ReturnToInitialPosition();

  static const int x_offset_ = 5;

  bool is_focus_ = false;
};

#endif  // ATM_BUTTON_H
