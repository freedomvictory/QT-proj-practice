#ifndef QMAPFORMMANGER_H
#define QMAPFORMMANGER_H

#include <QObject>
#include <QMap>

class QMapFormManger : public QObject
{
    Q_OBJECT
public:
    explicit QMapFormManger(QObject *parent = nullptr);

signals:

public slots:
    void GO_A();
    void GO_B();
    void GO_C();

private:
    QMap<QString, QWidget*> mywidgets;
};

#endif // QMAPFORMMANGER_H
