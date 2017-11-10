#ifndef ATM_CHECKBOX_H
#define ATM_CHECKBOX_H

#include <QCheckBox>
#include <QString>

class AtmCheckbox : public QCheckBox {
 public:
  AtmCheckbox(QWidget* parent = nullptr);
  ~AtmCheckbox();
};

#endif  // ATM_CHECKBOX_H
