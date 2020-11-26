#ifndef WINDOWMANGER_H
#define WINDOWMANGER_H

#include <QObject>

class WindowManger : public QObject
{
    Q_OBJECT
public:
    explicit WindowManger(QObject *parent = nullptr);

signals:

public slots:
};

#endif // WINDOWMANGER_H