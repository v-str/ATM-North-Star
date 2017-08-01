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

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void SetFrameScaling();

  AtmColorDesigner* color_designer_ = nullptr;

  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;
};

#endif  // DESCRIPTION_FRAME_H
