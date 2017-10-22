#ifndef GRAPHICAL_LOGIN_MENU_H
#define GRAPHICAL_LOGIN_MENU_H

#include <base_atm_frame.h>

#include <delta_size.h>
#include <geometry_composer.h>

class GraphicalLoginMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit GraphicalLoginMenu(QWidget* parent = nullptr);
  ~GraphicalLoginMenu();

 public slots:
  void ChangeGeometry(const DeltaSize& delta_size) override;

 private:
  GeometryComposer composer_;

  static constexpr double kXFactor = 1.0;
  static constexpr double kYFactor = 1.0;
};

#endif  // GRAPHICAL_LOGIN_MENU_H
