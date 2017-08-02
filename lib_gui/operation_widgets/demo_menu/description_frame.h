#ifndef DESCRIPTION_FRAME_H
#define DESCRIPTION_FRAME_H

#include <QFrame>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class AtmColorDesigner;
class AtmButton;
class QGridLayout;

class DescriptionFrame : public QFrame {
  Q_OBJECT
 public:
  DescriptionFrame(QWidget* parent = nullptr);
  ~DescriptionFrame();

  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  void PerformButtonsInitialization();
  void SetGridLayout();
  void SetGeometries();
  void ColorizeWidgets();

  AtmColorDesigner* color_designer_ = nullptr;

  AtmButton* account_info_button_ = nullptr;
  AtmButton* refill_button_ = nullptr;
  AtmButton* credit_app_button_ = nullptr;
  AtmButton* withdrawal_button_ = nullptr;
  AtmButton* statement_butotn_ = nullptr;

  QGridLayout* grid_layout_ = nullptr;

  DeltaSize delta_size_;
};

#endif  // DESCRIPTION_FRAME_H
