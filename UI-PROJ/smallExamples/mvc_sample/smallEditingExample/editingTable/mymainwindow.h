#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class myMainWindow;
}

class myMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit myMainWindow(QWidget *parent = 0);
    ~myMainWindow();

private:
    Ui::myMainWindow *ui;
public slots:
    void setMainWindowTitle(const QString&);
};

#endif // MYMAINWINDOW_H
