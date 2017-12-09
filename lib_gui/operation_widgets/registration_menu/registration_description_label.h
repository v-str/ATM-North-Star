#ifndef REGISTRATION_DESCRIPTION_LABEL_H
#define REGISTRATION_DESCRIPTION_LABEL_H

#include <QLabel>
#include <QString>

#include <QFontMetrics>

class QWidget;
class FontSizeGenerator;

class RegistrationDescriptionLabel : public QLabel {
  Q_OBJECT
 public:
  RegistrationDescriptionLabel(QWidget* parent = nullptr);
  ~RegistrationDescriptionLabel();

 public slots:
  void ChangeGeometry();

 private:
  void SetInitialSettings();

  FontSizeGenerator* font_size_generator_ = nullptr;

  static QString kDescriptionText;
};

#endif  // REGISTRATION_DESCRIPTION_LABEL_H
