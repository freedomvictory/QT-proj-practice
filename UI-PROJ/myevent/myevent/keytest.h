#ifndef KEYTEST_H
#define KEYTEST_H

#include <QWidget>
#include <QKeyEvent>
namespace Ui {
class keyTest;
}

class keyTest : public QWidget
{
    Q_OBJECT

public:
    explicit keyTest(QWidget *parent = nullptr);
    ~keyTest();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::keyTest *ui;
};

#endif // KEYTEST_H
