#ifndef TEXT_ANIMATION_H
#define TEXT_ANIMATION_H

#include <QObject>

#include <QString>

class QLabel;
class QTimer;
class QWidget;

class TextAnimation : public QObject {
  Q_OBJECT
 public:
  explicit TextAnimation(QWidget* parent = nullptr);

  void SetTextForAnimation(const QString& animation_text);
  void StartAnimation(int delay_msec, QLabel* label);

 private slots:
  void AnimateText();

 private:
  void ResetAnimationValues();
  bool IsStringEnd();

  QTimer* timer_ = nullptr;
  QLabel* animation_label_ = nullptr;

  QString animation_text_;
  QString assigned_text_;
  int symbol_count_ = 0;
};

#endif  // TEXT_ANIMATION_H
