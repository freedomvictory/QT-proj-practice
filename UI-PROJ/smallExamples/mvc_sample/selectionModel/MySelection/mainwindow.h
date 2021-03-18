#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QItemSelection;
class QStandardItemModel;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *m_standardModel;

private slots:
    void selectionChangeSlot(const QItemSelection & ,const QItemSelection &);
};

#endif // MAINWINDOW_H
