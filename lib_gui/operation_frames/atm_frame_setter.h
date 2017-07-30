#ifndef FRAME_SETTER_H
#define FRAME_SETTER_H

#include <QList>
#include <QObject>
#include <QRect>

class FrameAnimator;
class QFrame;
class AtmColorDesigner;
class QPushButton;

class AtmFrameSetter : public QObject {
  Q_OBJECT
 public:
  explicit AtmFrameSetter(QFrame* frame = nullptr);
  virtual ~AtmFrameSetter();

  void SetOperationFrame(QFrame* frame);

  void SetAnimationDirection(unsigned int hide_to, unsigned int extrude_from);
  void SetAnimationDuration(unsigned int duration_msec);

  void ColorizeButtons(QList<QPushButton*>& button_list);

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
  void InitializeAnimationObjects(QFrame* frame);

  void SetAnimationConnections();

  AtmColorDesigner* color_designer_ = nullptr;
  FrameAnimator* hide_animator_ = nullptr;
  FrameAnimator* extrude_animator_ = nullptr;
};

#endif  // FRAME_SETTER_H
