#include <description_menu_geometry.h>

QRect DescriptionMenuGeometry::kDescriptionMenu = {5, 30, 580, 355};
QRect DescriptionMenuGeometry::kBackButton = {20, 320, 50, 30};

QRect DescriptionMenuGeometry::kDescriptionFrame = {10, 10, 260, 280};
QRect DescriptionMenuGeometry::kDescriptionLabel = {280, 60, 290, 220};
QRect DescriptionMenuGeometry::kDescriptionTitle = {280, 10, 290, 40};

QRect DescriptionMenuGeometry::DescriptionMenu() { return kDescriptionMenu; }

QRect DescriptionMenuGeometry::BackButton() { return kBackButton; }

QRect DescriptionMenuGeometry::DescriprionFrame() { return kDescriptionFrame; }

QRect DescriptionMenuGeometry::DescriprionLabel() { return kDescriptionLabel; }

QRect DescriptionMenuGeometry::DescriptionTitle() { return kDescriptionTitle; }
