#ifndef KEYTEST_H
#define KEYTEST_H

#include <QWidget>

namespace Ui {
class keyTest;
}

class keyTest : public QWidget
{
    Q_OBJECT

public:
    explicit keyTest(QWidget *parent = nullptr);
    ~keyTest();

private:
    Ui::keyTest *ui;
};

#endif // KEYTEST_H
