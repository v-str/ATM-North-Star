#ifndef OPERATION_FRAME_H
#define OPERATION_FRAME_H

#include <QObject>
#include <QRect>

class FrameAnimator;
class QWidget;

class OperationFrame : public QObject {
  Q_OBJECT
 public:
  explicit OperationFrame(QWidget* widget = nullptr);
  virtual ~OperationFrame();

  void SetAnimationDirection(unsigned int hide_to, unsigned int extrude_from);

 public slots:
  void StartHidingFrame(const QRect& geometry);
  void StartExtrudingFrame(const QRect& geometry);

  void FinishHiding();
  void FinishExtruding();

 signals:
  void HidingComplete();
  void ExtrudingComplete();

  void PassParametersForHide(const QRect& geometry);
  void PassParametersForExtrude(const QRect& geometry);

 private:
  void SetConnections();

  FrameAnimator* hide_animator_ = nullptr;
  FrameAnimator* extrude_animator_ = nullptr;
};

#endif  // OPERATION_FRAME_H
