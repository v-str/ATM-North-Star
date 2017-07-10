#include <v_group_composer.h>

#include <QWidget>

void VGroupComposer::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void VGroupComposer::SetInitialGroupGeometry(
    const QVector<QRect>& widget_vector) {
  geometry_vector_ = widget_vector;
}

void VGroupComposer::ScaleVGroup(QVector<QWidget*> scale_vector) {
  geometry_.setX(geometry_vector_[0].x());
  geometry_.setY(geometry_vector_[0].y());
  geometry_.setWidth(geometry_vector_[0].width() + delta_size_.Width() * 0.1);
  geometry_.setHeight(geometry_vector_[0].height() +
                      delta_size_.Height() * 0.1);
  scale_vector[0]->setGeometry(geometry_);

  for (int element = 1; element < scale_vector.size(); ++element) {
    ComputeElementPosition(scale_vector[element], scale_vector[element - 1]);
    ComputeElementSize(element);
    scale_vector[element]->setGeometry(geometry_);
  }
}

void VGroupComposer::SetSpace(int space) { space_ = space; }

void VGroupComposer::ComputeElementPosition(QWidget* widget_x_pos,
                                            QWidget* widget_y_pos) {
  geometry_.setX(widget_x_pos->x());
  geometry_.setY(widget_y_pos->y() + widget_y_pos->height() + space_);
}

void VGroupComposer::ComputeElementSize(int element_number) {
  geometry_.setWidth(geometry_vector_[element_number].width() +
                     delta_size_.Width() * 0.1);
  geometry_.setHeight(geometry_vector_[element_number].height() +
                      delta_size_.Height() * 0.1);
}
