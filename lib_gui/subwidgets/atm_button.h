#ifndef ATM_BUTTON_H
#define ATM_BUTTON_H

#include <QPushButton>

#include <QRect>

class QString;
class QWidget;

class AtmButton : public QPushButton {
  Q_OBJECT
 public:
  AtmButton(QWidget* widget = nullptr);
  AtmButton(const QString& text, QWidget* widget = nullptr);

  void SetGeometry(const QRect& geometry);

  ~AtmButton();

 protected:
  void focusInEvent(QFocusEvent*);
  void focusOutEvent(QFocusEvent*);

 private:
  QRect geometry_;
};

#endif  // ATM_BUTTON_H
