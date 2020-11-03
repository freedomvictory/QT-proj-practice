#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
class myclass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ getUserName WRITE setUserName NOTIFY userNameChanged)
public:
    explicit myclass(QObject *parent = nullptr);

    QString getUserName() const
    {
        return m_userName;
    }
    void setUserName(QString userName)
    {
        m_userName = userName;
        emit userNameChanged(userName);
    }

private:
    QString m_userName;

signals:
    void userNameChanged(QString);




};

#endif // MYCLASS_H
