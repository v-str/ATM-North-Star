#ifndef REGISTRATION_DESCRIPTION_H
#define REGISTRATION_DESCRIPTION_H

#include <base_atm_frame.h>

#include <familiarized_checkbox.h>
#include <font_size_controller.h>

class QWidget;
class QRect;
class RegistrationDescriptionLabel;

class RegistrationDescription : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit RegistrationDescription(QWidget* parent = nullptr);
  ~RegistrationDescription();

 public slots:
  void ChangeGeometry() override;

 private:
  DeltaSize CalculateDeltaSize(const DeltaSize& app_delta_size,
                               const DeltaSize& back_button_delta_size);
  void SetConnections();

  RegistrationDescriptionLabel* description_label_ = nullptr;
  FamiliarizedCheckbox* familiarized_checkbox_ = nullptr;
};

#endif  // REGISTRATION_DESCRIPTION_H
