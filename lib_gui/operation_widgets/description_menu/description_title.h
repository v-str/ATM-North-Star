#ifndef DESCRIPTION_TITLE_H
#define DESCRIPTION_TITLE_H

#include <QLabel>

class QWidget;

class DescriptionTitle : public QLabel {
  Q_OBJECT
 public:
  explicit DescriptionTitle(QWidget* parent = nullptr);
  ~DescriptionTitle();

 private:
  void ColorizeWidget();
};

#endif  // DESCRIPTION_TITLE_H
