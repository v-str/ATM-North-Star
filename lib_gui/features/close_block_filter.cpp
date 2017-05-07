#include <close_block_filter.h>

#include <QEvent>
#include <QKeyEvent>

CloseBlockFilter::CloseBlockFilter(QObject* obj) : QObject(obj) {}

bool CloseBlockFilter::eventFilter(QObject* watched, QEvent* event) {
  if (event->type() == QEvent::KeyPress || QEvent::KeyRelease) {
    if (static_cast<QKeyEvent*>(event)->key() == Qt::Key_Space) {
      event->ignore();
      return true;
    }
  }
  return false;
}
