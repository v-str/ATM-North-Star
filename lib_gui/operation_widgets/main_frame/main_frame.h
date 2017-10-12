#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <base_atm_frame.h>

class MainFrame : public BaseAtmFrame {
  Q_OBJECT

 public:
  MainFrame(QWidget* parent = nullptr);
  ~MainFrame();
};

#endif  // MAIN_FRAME_H
