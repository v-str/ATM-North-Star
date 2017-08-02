#include <description_menu_geometry.h>

QRect DescriptionMenuGeometry::kDescriptionMenu = {5, 30, 580, 355};
QRect DescriptionMenuGeometry::kBackButton = {5, 320, 50, 30};

QRect DescriptionMenuGeometry::kDescriptionFrame = {10, 80, 560, 210};
QRect DescriptionMenuGeometry::kDescriptionLabel = {10, 10, 560, 60};

QRect DescriptionMenuGeometry::DescriptionMenu() { return kDescriptionMenu; }

QRect DescriptionMenuGeometry::BackButton() { return kBackButton; }

QRect DescriptionMenuGeometry::DescriprionFrame() { return kDescriptionFrame; }

QRect DescriptionMenuGeometry::DescriprionLabel() { return kDescriptionLabel; }
