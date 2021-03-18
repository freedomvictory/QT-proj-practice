#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QStandardItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QList<QStandardItem *> prepareRow(const QString& first,
                                      const QString& second,
                                      const QString& third);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
