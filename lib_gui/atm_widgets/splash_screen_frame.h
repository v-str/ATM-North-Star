#ifndef SPLASH_SCREEN_FRAME_H
#define SPLASH_SCREEN_FRAME_H

#include <base_atm_frame.h>

#include <atm_color_designer.h>
#include <splash_screen_composer.h>

class QLabel;
class QString;

class SplashScreenFrame : public BaseAtmFrame {
  Q_OBJECT

 public:
  explicit SplashScreenFrame(QWidget* parent = nullptr);
  ~SplashScreenFrame();

  void SetCompanyName(const QString& company_name);

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetSplashScreenSettings();
  void InitializeObjects();
  void PaintWidgets();

  SplashScreenComposer composer_;
  AtmColorDesigner color_designer_;

  QLabel* version_label_ = nullptr;
  QLabel* company_name_label_ = nullptr;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;

  static const int kHalfASecond = 500;
};

#endif  // SPLASH_SCREEN_FRAME_H
