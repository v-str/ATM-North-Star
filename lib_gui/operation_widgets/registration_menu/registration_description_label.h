#ifndef REGISTRATION_DESCRIPTION_LABEL_H
#define REGISTRATION_DESCRIPTION_LABEL_H

#include <QLabel>

#include <atm_color_designer.h>

class QWidget;

class RegistrationDescriptionLabel : public QLabel {
  Q_OBJECT
 public:
  RegistrationDescriptionLabel(QWidget* parent = nullptr);
  ~RegistrationDescriptionLabel();

 private:
  void SetInitialSettings();
  void SetText();

  AtmColorDesigner color_designer_;
};

#endif  // REGISTRATION_DESCRIPTION_LABEL_H
