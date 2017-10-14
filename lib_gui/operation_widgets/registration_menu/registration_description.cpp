#include <registration_description.h>

#include <QRect>
#include <QWidget>

RegistrationDescription::RegistrationDescription(QWidget* parent)
    : BaseAtmFrame(parent, BackButtonCondition::kBackButtonDeactivated) {}

RegistrationDescription::~RegistrationDescription() {}

void RegistrationDescription::ControlIndentation(
    const QRect& control_geometry) {
  setGeometry(geometry().x(), geometry().y(), geometry().width(),
              control_geometry.y() - kIndent);
}
