#ifndef EXIT_DIALOG_H
#define EXIT_DIALOG_H

#include <QDialog>

#include <atm_color_designer.h>

class QTimer;
class QString;
class QRect;

namespace Ui {
class ExitDialog;
}

class ExitDialog : public QDialog {
  Q_OBJECT

 public:
  explicit ExitDialog(QWidget* parent = nullptr);
  ~ExitDialog();

  void ShowWidgetOnCenterAt(const QRect& widget_geometry);

 private:
  void SetBackgroundColor();
  void SetExitDialogAppearance();

  void SetConnections();
  void SetInitialProperties();
  void PaintWidgets();
  void SetFontStyle();

  Ui::ExitDialog* ui = nullptr;

  AtmColorDesigner color_designer_;

  static const int kWidgetWidth = 300;
  static const int kWidgetHeight = 150;
};

#endif  // EXIT_DIALOG_H
