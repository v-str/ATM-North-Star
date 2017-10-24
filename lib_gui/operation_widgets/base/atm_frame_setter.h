#ifndef ATM_FRAME_SETTER_H
#define ATM_FRAME_SETTER_H

#include <QList>
#include <QObject>
#include <QRect>

class FrameAnimator;
class QFrame;
class QPushButton;

class AtmFrameSetter : public QObject {
  Q_OBJECT
 public:
  explicit AtmFrameSetter(QFrame* frame = nullptr);
  virtual ~AtmFrameSetter();

  void SetOperationFrame(QFrame* frame);

  void SetAnimationDirection(unsigned int hide_to, unsigned int extrude_from);
  void SetAnimationDuration(unsigned int duration_msec);

  void ColorizeButtons(QList<QPushButton*>* button_list);

 public slots:
  void StartHideFrame(const QRect& geometry);
  void StartExtrudingFrame(const QRect& geometry);

  void FinishHiding();
  void FinishExtruding();

 signals:
  void HidingComplete();
  void ExtrudingComplete();

  void PassGeometryForHide(const QRect& geometry);
  void PassGeometryForExtrude(const QRect& geometry);

 private:
  void InitializeAnimationObjects(QFrame* frame);

  void SetAnimationConnections();

  FrameAnimator* hide_animator_ = nullptr;
  FrameAnimator* extrude_animator_ = nullptr;
};

#endif  // ATM_FRAME_SETTER_H
