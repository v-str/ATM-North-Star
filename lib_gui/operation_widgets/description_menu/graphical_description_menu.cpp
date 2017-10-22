#include <graphical_description_menu.h>

#include <QFrame>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <description_frame.h>
#include <description_label.h>
#include <description_menu_geometry.h>
#include <description_title.h>
#include <side.h>

GraphicalDescriptionMenu::GraphicalDescriptionMenu(QWidget* parent)
    : BaseAtmFrame(parent),
      description_label_(new DescriptionLabel(this)),
      description_frame_(new DescriptionFrame(this)),
      description_title_(new DescriptionTitle(this)) {
  SetInitialFrameGeometry(DescriptionMenuGeometry::DescriptionMenu());

  description_title_->setText("Description");

  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);

  SetConnections();
}

GraphicalDescriptionMenu::~GraphicalDescriptionMenu() {}

void GraphicalDescriptionMenu::SetDeltaSize(const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  delta_size_ = delta_size;
}

void GraphicalDescriptionMenu::resizeEvent(QResizeEvent*) {
  ScaleBackButton();
  BaseAtmFrame::SetDeltaSize(delta_size_);
  composer_.SetDeltaSize(delta_size_);

  ComposeDescriptionFrame();
  ComposeDescriptionLabel();
  ComposeDescriptionTitle();
}

void GraphicalDescriptionMenu::ComposeDescriptionFrame() {
  composer_.SetTransformationType(GeometryComposer::kStretch);
  composer_.SetStretchFactor(0.5, 1.0);
  composer_.SetStretchSide(Side::kDown | Side::kRight);
  composer_.ComposeGeometry(DescriptionMenuGeometry::DescriprionFrame(),
                            description_frame_);
}

void GraphicalDescriptionMenu::ComposeDescriptionLabel() {
  composer_.SetTransformationType(GeometryComposer::kScale);
  composer_.SetShiftFactor(0.5, 0.0);
  composer_.SetShiftSide(Side::kDown | Side::kRight);
  composer_.SetStretchFactor(0.5, 1.0);
  composer_.SetStretchSide(Side::kDown | Side::kRight);
  composer_.ComposeGeometry(DescriptionMenuGeometry::DescriprionLabel(),
                            description_label_);
}

void GraphicalDescriptionMenu::ComposeDescriptionTitle() {
  composer_.SetTransformationType(GeometryComposer::kScale);
  composer_.SetShiftFactor(0.5, 0.0);
  composer_.SetShiftSide(Side::kRight);
  composer_.SetStretchFactor(0.5, 0.0);
  composer_.SetStretchSide(Side::kDown | Side::kRight);
  composer_.ComposeGeometry(DescriptionMenuGeometry::DescriptionTitle(),
                            description_title_);
}

void GraphicalDescriptionMenu::SetConnections() {
  connect(description_frame_, SIGNAL(AccountInfoButtonClicked()),
          description_label_, SLOT(ShowAccountInfo()));
  connect(description_frame_, SIGNAL(CashRefillButtonClicked()),
          description_label_, SLOT(ShowCashRefillInfo()));
  connect(description_frame_, SIGNAL(CreditAppButtonClicked()),
          description_label_, SLOT(ShowCreditAppInfo()));
  connect(description_frame_, SIGNAL(CashWithdrawalButtonClicked()),
          description_label_, SLOT(ShowWithdrawalInfo()));
  connect(description_frame_, SIGNAL(StatementButtonClicked()),
          description_label_, SLOT(ShowStatementInfo()));
}
