#ifndef REGISTRATION_DESCRIPTION_H
#define REGISTRATION_DESCRIPTION_H

#include <base_atm_frame.h>

#include <font_size_controller.h>

class QWidget;
class QRect;
class RegistrationDescriptionLabel;
class QCheckBox;
class QVBoxLayout;
class QFrame;

class RegistrationDescription : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit RegistrationDescription(QWidget* parent = nullptr);
  ~RegistrationDescription();

 public slots:
  void ChangeGeometry() override;

 private:
  void SetCheckBoxFrame();

  DeltaSize CalculateDeltaSize(const DeltaSize& app_delta_size,
                               const DeltaSize& back_button_delta_size);
  void SetConnections();

  QVBoxLayout* checkbox_v_layout_ = nullptr;
  RegistrationDescriptionLabel* description_label_ = nullptr;
  QFrame* checkbox_frame_ = nullptr;
  QCheckBox* familiarized_checkbox_ = nullptr;
  QCheckBox* not_familiarized_checkbox_ = nullptr;
};

#endif  // REGISTRATION_DESCRIPTION_H
