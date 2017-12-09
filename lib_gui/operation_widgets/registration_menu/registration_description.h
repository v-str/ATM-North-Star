#ifndef REGISTRATION_DESCRIPTION_H
#define REGISTRATION_DESCRIPTION_H

#include <base_atm_frame.h>

#include <QFont>

#include <atm_checkbox.h>

class QWidget;
class QRect;
class RegistrationDescriptionLabel;
class FontSizeGenerator;

class RegistrationDescription : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit RegistrationDescription(QWidget* parent = nullptr);
  ~RegistrationDescription();

 signals:
  void UserFamiliarized();
  void UserNotFamiliarized();

 public slots:
  void ChangeGeometry() override;
  void CheckBoxClicked(int state);
  void DeactivateFamiliarizing();

 private:
  DeltaSize CalculateDeltaSize(const DeltaSize& app_delta_size,
                               const DeltaSize& back_button_delta_size);
  void SetConnections();

  RegistrationDescriptionLabel* description_label_ = nullptr;
  AtmCheckbox* atm_checkbox_ = nullptr;
};

#endif  // REGISTRATION_DESCRIPTION_H
