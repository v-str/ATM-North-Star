#ifndef ATM_MAIN_WIDGET_H
#define ATM_MAIN_WIDGET_H

#include <QMainWindow>

namespace Ui {
class AtmMainWidget;
}

class AtmMainWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit AtmMainWidget(QWidget *parent = 0);
    ~AtmMainWidget();

private:
    Ui::AtmMainWidget *ui;
};

#endif // ATM_MAIN_WIDGET_H
