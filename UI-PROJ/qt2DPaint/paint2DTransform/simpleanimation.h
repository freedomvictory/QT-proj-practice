#ifndef SIMPLEANIMATION_H
#define SIMPLEANIMATION_H

#include <QWidget>

class QTimer;

class simpleAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit simpleAnimation(QWidget *parent = nullptr);

signals:

public slots:

private:

    QTimer *timer;
    int angle;

protected:
        void paintEvent(QPaintEvent *event);
};

#endif // SIMPLEANIMATION_H
