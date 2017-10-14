#include <registration_description.h>

#include <QWidget>

RegistrationDescription::RegistrationDescription(QWidget* parent)
    : BaseAtmFrame(parent, BackButtonCondition::kBackButtonDeactivated) {}

RegistrationDescription::~RegistrationDescription() {}
