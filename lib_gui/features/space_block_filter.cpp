#include <space_block_filter.h>

#include <QEvent>
#include <QKeyEvent>

SpaceBlockFilter::SpaceBlockFilter(QObject* obj) : QObject(obj) {}

bool SpaceBlockFilter::eventFilter(QObject*, QEvent* event) {
  if (event->type() == QEvent::KeyPress || QEvent::KeyRelease) {
    if (static_cast<QKeyEvent*>(event)->key() == Qt::Key_Space) {
      event->ignore();
      return true;
    }
  }
  return false;
}
