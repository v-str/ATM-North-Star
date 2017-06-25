#ifndef ABSTRACT_OPERATION_FRAME_H
#define ABSTRACT_OPERATION_FRAME_H

#include <QFrame>
#include <QObject>

class QWidget;

class AbstractOperationFrame : public QFrame {
  Q_OBJECT
 public:
  AbstractOperationFrame(QWidget* parent = nullptr);
  ~AbstractOperationFrame();

  virtual void PaintSubwidgets() = 0;

 protected:
  void paintEvent(QPaintEvent*);

 private:
  void SetInitialSettings();
};

#endif  // ABSTRACT_OPERATION_FRAME_H
