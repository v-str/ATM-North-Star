#ifndef DEMO_TRANSACTION_MENU_FRAME_H
#define DEMO_TRANSACTION_MENU_FRAME_H

#include <QFrame>

class QWidget;

class DemoTransactionMenuFrame : public QFrame {
  Q_OBJECT
 public:
  DemoTransactionMenuFrame(QWidget* parent = nullptr);
  ~DemoTransactionMenuFrame();
};

#endif  // DEMO_TRANSACTION_MENU_FRAME_H
