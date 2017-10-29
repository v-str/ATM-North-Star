#ifndef REGISTRATION_DESCRIPTION_LABEL_H
#define REGISTRATION_DESCRIPTION_LABEL_H

#include <QLabel>
#include <QString>

#include <QFontMetrics>

#include <font_size_controller.h>

class QWidget;

class RegistrationDescriptionLabel : public QLabel {
  Q_OBJECT
 public:
  RegistrationDescriptionLabel(QWidget* parent = nullptr);
  ~RegistrationDescriptionLabel();

 public slots:
  void ChangeGeometry();

 private:
  void SetInitialSettings();

  static QString kDescriptionText;
};

#endif  // REGISTRATION_DESCRIPTION_LABEL_H
