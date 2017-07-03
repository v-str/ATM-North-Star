#ifndef ATM_BUTTON_H
#define ATM_BUTTON_H

#include <QPushButton>

class QString;
class QWidget;

class AtmButton : public QPushButton {
  Q_OBJECT
 public:
  AtmButton(QWidget* widget = nullptr);
  AtmButton(const QString& text, QWidget* widget = nullptr);

  ~AtmButton();
};

#endif  // ATM_BUTTON_H
