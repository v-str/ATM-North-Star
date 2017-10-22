#ifndef BASE_ATM_FRAME_H
#define BASE_ATM_FRAME_H

#include <QFrame>
#include <QList>
#include <QObject>
#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>

class AtmButton;
class AtmFrameSetter;
class QWidget;
class QPushButton;

class BaseAtmFrame : public QFrame {
  Q_OBJECT
 public:
  enum BackButtonCondition { kBackButtonActivated, kBackButtonDeactivated };

  explicit BaseAtmFrame(
      QWidget* parent = nullptr,
      BackButtonCondition back_button_condition = kBackButtonActivated);
  ~BaseAtmFrame();

  void SetDeltaSize(const DeltaSize& delta_size);
  void SetInitialFrameGeometry(const QRect& geometry);
  void SetFrameAnimation(unsigned int hide_to,
                         unsigned int extrude_from,
                         QFrame* animated_frame,
                         unsigned int duration_msec = 500);

  void ColorizeButtons(QList<QPushButton*>* button_list);

  AtmButton* GetBackButtonGeometry() const;

 signals:
  void BackButtonClicked();
  void PassGeometryForHide(const QRect&);
  void PassGeometryForExtrude(const QRect&);
  void GeometryChanged(const DeltaSize&);
  void FrameClosed();
  void FrameOpened();

 public slots:
  virtual void ChangeGeometry(const DeltaSize& delta_size) = 0;

  void ProcessBackButtonClick();
  void Show();
  void Close();

 private slots:
  void PerformClosing();
  void PerformOpening();

 private:
  void ColorizeBackButton();
  void SetBasicConnections();
  void SetBackButton();

  AtmButton* back_button_ = nullptr;
  AtmFrameSetter* frame_setter_ = nullptr;

  QRect initial_frame_geometry_;
  DeltaSize delta_size_;

  bool is_back_button_activated_ = false;
};

#endif  // BASE_ATM_FRAME_H
