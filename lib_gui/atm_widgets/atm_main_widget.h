#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QFrame>
#include <QMainWindow>

#include <atm_color_designer.h>
#include <main_widget_composer.h>

class QString;
class ApplicationColor;
class QTimer;
class GraphicalInitialMenu;
class GraphicalRegistrationMenu;
class GraphicalLoginMenu;
class TimeLabel;
class DateLabel;

namespace Ui {
class AtmMainWidget;
}

class AtmMainWidget : public QMainWindow {
  Q_OBJECT

 public:
  explicit AtmMainWidget(QWidget* parent = nullptr);
  ~AtmMainWidget();

  void SetMenu(QWidget* widget);

  QFrame* GetMainFrame() const;
  DeltaSize GetDeltaSize() const;

 signals:
  void LoginButtonClicked();
  void RegistrationButtonClicked();
  void ShowInitialMenu();
  void MainWidgetGeometryChanged(const DeltaSize&);

 public slots:
  void ProcessLoginButtonClick();
  void ProcessRegistrationButtonClick();
  void ProcessInitialMenuOpening();

 protected:
  void resizeEvent(QResizeEvent* event);

 private:
  void SetInitialSettings();              // -
  void InitializeObject();                // -
  void PaintWidgets();                    // +
  void SetImages();                       // +
  void SetInitialMainWidgetProperties();  // +
  void SetConnections();                  // -
  void ComposeWidgets();                  // -
  void ComputeDeltaSize();                // -

  Ui::AtmMainWidget* ui = nullptr;
  GraphicalInitialMenu* initial_menu_ = nullptr;
  GraphicalRegistrationMenu* registration_menu_ = nullptr;
  GraphicalLoginMenu* login_menu_ = nullptr;

  TimeLabel* time_label_ = nullptr;
  DateLabel* date_label_ = nullptr;

  AtmColorDesigner color_designer_;
  MainWidgetComposer main_widget_composer_;

  int delta_width_ = 0;
  int delta_height_ = 0;

  static const int kAppWidth = 600;
  static const int kAppHeight = 400;
};

#endif  // ATM_MAIN_WIDGET_H
