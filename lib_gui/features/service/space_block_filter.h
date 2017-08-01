#ifndef SPACE_BLOCK_FILTER_H
#define SPACE_BLOCK_FILTER_H

#include <QObject>

class SpaceBlockFilter : public QObject {
  Q_OBJECT

 public:
  SpaceBlockFilter(QObject* obj = nullptr);

 protected:
  virtual bool eventFilter(QObject* watched, QEvent* event);
};

#endif  // SPACE_BLOCK_FILTER_H
