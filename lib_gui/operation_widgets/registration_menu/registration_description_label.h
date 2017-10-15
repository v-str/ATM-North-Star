#ifndef REGISTRATION_DESCRIPTION_LABEL_H
#define REGISTRATION_DESCRIPTION_LABEL_H

#include <QLabel>

class QWidget;

class RegistrationDescriptionLabel : public QLabel {
  Q_OBJECT
 public:
  RegistrationDescriptionLabel(QWidget* parent = nullptr);
  ~RegistrationDescriptionLabel();

 private:
  void SetText();
};

#endif  // REGISTRATION_DESCRIPTION_LABEL_H
