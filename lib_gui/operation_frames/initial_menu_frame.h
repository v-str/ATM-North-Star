#ifndef INITIAL_MENU_FRAME_H
#define INITIAL_MENU_FRAME_H

#include <abstract_operation_frame.h>

#include <QObject>

class QWidget;

class InitialMenuFrame : public AbstractOperationFrame {
  Q_OBJECT
 public:
  InitialMenuFrame(QWidget* parent);
  ~InitialMenuFrame();

 private:
};

#endif  // INITIAL_MENU_FRAME_H
