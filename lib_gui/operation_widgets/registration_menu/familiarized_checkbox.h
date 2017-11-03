#ifndef FAMILIARIZED_CHECKBOX_H
#define FAMILIARIZED_CHECKBOX_H

#include <QCheckBox>
#include <QString>

class FamiliarizedCheckbox : public QCheckBox {
 public:
  FamiliarizedCheckbox(QWidget* parent = nullptr);
  ~FamiliarizedCheckbox();
};

#endif  // FAMILIARIZED_CHECKBOX_H
