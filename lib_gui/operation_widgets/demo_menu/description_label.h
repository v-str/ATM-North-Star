#ifndef DESCRIPTION_LABEL_H
#define DESCRIPTION_LABEL_H

#include <QLabel>

class QWidget;

class DescriptionLabel : public QLabel {
  Q_OBJECT
 public:
  DescriptionLabel(QWidget* parent = nullptr);
  ~DescriptionLabel();
};

#endif  // DESCRIPTION_LABEL_H
