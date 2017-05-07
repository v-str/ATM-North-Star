#ifndef CLOSE_BLOCK_FILTER_H
#define CLOSE_BLOCK_FILTER_H

#include <QObject>

class CloseBlockFilter : public QObject {
  Q_OBJECT

 public:
  CloseBlockFilter(QObject* obj = nullptr);

 protected:
  virtual bool eventFilter(QObject* watched, QEvent* event);
};

#endif  // CLOSE_BLOCK_FILTER_H
