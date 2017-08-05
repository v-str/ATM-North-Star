#ifndef DESCRIPTION_TITLE_H
#define DESCRIPTION_TITLE_H

#include <QLabel>

class QWidget;

class DescriptionTitle : public QLabel {
  Q_OBJECT
 public:
  explicit DescriptionTitle(QWidget* parent = nullptr);
  ~DescriptionTitle();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void ColorizeWidget();

  static const int kDivideFontCoefficient = 40;
  static const int kInitialFontSize = 11;
};

#endif  // DESCRIPTION_TITLE_H
