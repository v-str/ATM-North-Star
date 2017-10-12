#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QFrame>
#include <QMainWindow>

#include <main_widget_composer.h>

class QString;
class ApplicationColor;
class QTimer;
class GraphicalInitialMenu;
class SplashScreenFrame;
class MainFrame;

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
  void EnterIsPressed();

 public slots:
  void ProcessLoginButtonClick();
  void ProcessRegistrationButtonClick();
  void ProcessInitialMenuOpening();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetInitialSettings();
  void InitializeObjects();
  void SetImages();
  void SetInitialMainWidgetProperties();
  void SetConnections();
  void ComposeWidgets();
  void ComputeDeltaSize();

  GraphicalInitialMenu* initial_menu_ = nullptr;
  SplashScreenFrame* splash_screen_ = nullptr;
  MainFrame* main_frame_ = nullptr;

  MainWidgetComposer main_widget_composer_;

  int delta_width_ = 0;
  int delta_height_ = 0;

  static const int kAppWidth = 600;
  static const int kAppHeight = 400;
};

#endif  // ATM_MAIN_WIDGET_H
