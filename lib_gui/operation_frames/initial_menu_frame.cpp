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
  example_button_->setGeometry(220, 112, 140, 40);

  QString background_color = ApplicationColor::ApplicationBackgroundColor();
  QString frame_color = ApplicationColor::MainColor();

  QString style_sheet =
      "QFrame {"
      "background-color: %1;"
      "border: 1px solid %2;"
      "border-radius: 3px;"
      "}";

  setStyleSheet(style_sheet.arg(background_color, frame_color));
}

InitialMenuFrame::~InitialMenuFrame() { delete atm_color_designer_; }

void InitialMenuFrame::PaintWidgets() {
  atm_color_designer_->PaintWidgetSet(QList<QPushButton*>{example_button_});
}
