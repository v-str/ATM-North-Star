#include <text_animation.h>

#include <QLabel>
#include <QTimer>
#include <QWidget>

TextAnimation::TextAnimation(QWidget* parent)
    : QObject(parent), timer_(new QTimer(parent)) {
  connect(timer_, SIGNAL(timeout()), SLOT(AnimateText()));
}

void TextAnimation::SetTextForAnimation(const QString& animation_text) {
  animation_text_.clear();
  assigned_text_.clear();
  symbol_count_ = 0;
  animation_text_ = animation_text;
}

void TextAnimation::StartAnimation(int delay_msec, QLabel* label) {
  timer_->start(delay_msec);
  animation_label_ = label;
}

void TextAnimation::AnimateText() {
  assigned_text_ += animation_text_[symbol_count_];
  animation_label_->setText(assigned_text_);
  if (symbol_count_ == animation_text_.size() - 1) {
    timer_->stop();
  }
  symbol_count_++;
}
