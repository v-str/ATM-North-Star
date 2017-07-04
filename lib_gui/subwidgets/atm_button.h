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

 public slots:
  void MakeOffset();

 signals:
  void Hovered();

 protected:
  void focusInEvent(QFocusEvent*);
  void focusOutEvent(QFocusEvent*);

  //  void HoverEnter(QHoverEvent*);
  //  void HoverLeave(QHoverEvent*);

  //  bool event(QEvent* e);

  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

 private:
  static const int x_offset_ = 5;
};

#endif  // ATM_BUTTON_H
