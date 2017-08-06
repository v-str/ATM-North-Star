#ifndef DESCRIPTION_TITLE_H
#define DESCRIPTION_TITLE_H

#include <QLabel>

class QWidget;
class FontSizeController;

class DescriptionTitle : public QLabel {
  Q_OBJECT
 public:
  explicit DescriptionTitle(QWidget* parent = nullptr);
  ~DescriptionTitle();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void ColorizeWidget();

  FontSizeController* font_size_controller_ = nullptr;
};

#endif  // DESCRIPTION_TITLE_H
