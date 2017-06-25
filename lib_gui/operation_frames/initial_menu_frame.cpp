#include <initial_menu_frame.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_color_designer.h>

InitialMenuFrame::InitialMenuFrame(QWidget* parent)
    : QFrame(parent),
      example_button_(new QPushButton(this)),
      atm_color_designer_(new AtmColorDesigner) {
  PaintWidgets();
  example_button_->setGeometry(220, 112, 140, 40);
  example_button_->setText("ATM");
}

InitialMenuFrame::~InitialMenuFrame() { delete atm_color_designer_; }

void InitialMenuFrame::PaintWidgets() {
  atm_color_designer_->PaintInitialFrame(this);
  atm_color_designer_->PaintWidgetSet(QList<QPushButton*>{example_button_});
}
