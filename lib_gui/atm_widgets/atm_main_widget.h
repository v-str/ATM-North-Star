#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QFrame>
#include <QMainWindow>

#include <main_widget_composer.h>

class QString;
class GraphicalInitialMenu;
class SplashScreenFrame;
class MainFrame;
class ExitDialog;

namespace Ui {
class AtmMainWidget;
}

class AtmMainWidget : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmMainWidget(QWidget* parent = nullptr);
  ~AtmMainWidget();

  void SetCompanyName(const QString& company_name);

  QFrame* GetMainFrame() const;

 signals:
  void LoginButtonClicked();
  void RegistrationButtonClicked();
  void ShowInitialMenu();
  void MainWidgetGeometryChanged(const DeltaSize&);
  void SplashScreenEnterPressed();
  void Exit();

 public slots:
  void ProcessLoginButtonClick();
  void ProcessRegistrationButtonClick();
  void ProcessInitialMenuOpening();

 private slots:
  void ShowExitWidget();

 protected:
  void keyPressEvent(QKeyEvent* event);
  void resizeEvent(QResizeEvent*);

 private:
  void SetInitialSettings();
  void InitializeObjects();
  void SetImages();
  void SetInitialMainWidgetProperties();
  void SetConnections();
  void ComposeWidgets();
  void ComputeDeltaSize();

  void CheckSplashScreenCondition();

  SplashScreenFrame* splash_screen_ = nullptr;
  GraphicalInitialMenu* initial_menu_ = nullptr;
  MainFrame* main_frame_ = nullptr;
  ExitDialog* exit_dialog_ = nullptr;

  MainWidgetComposer main_widget_composer_;

  int delta_width_ = 0;
  int delta_height_ = 0;

  static const int kAppWidth = 600;
  static const int kAppHeight = 400;

  bool is_splash_screen_closed_ = false;
};

#endif  // ATM_MAIN_WIDGET_H
