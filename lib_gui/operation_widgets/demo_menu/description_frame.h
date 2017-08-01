#ifndef DESCRIPTION_FRAME_H
#define DESCRIPTION_FRAME_H

#include <QFrame>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class AtmColorDesigner;

class DescriptionFrame : public QFrame {
  Q_OBJECT
 public:
  DescriptionFrame(QWidget* parent = nullptr);
  ~DescriptionFrame();

  void SetDeltaSize(const DeltaSize& delta_size);

 private:
  void SetGeometries();
  void ColorizeWidgets();

  AtmColorDesigner* color_designer_ = nullptr;

  DeltaSize delta_size_;
};

#endif  // DESCRIPTION_FRAME_H
