# QT Property 


## Instruction 

QT provide powerful property system based on meta-object system. 
To declare property in a class. This class must inherit from `QObject`, and use `Q_PROPERTY()` Macro before declare property. 

## How to use `Q_PROPERTY`

```c++
  Q_PROPERTY(type name
             (READ getFunction [WRITE setFunction] |
              MEMBER memberName [(READ getFunction | WRITE setFunction)])
             [RESET resetFunction]
             [NOTIFY notifySignal]
             [REVISION int]
             [DESIGNABLE bool]
             [SCRIPTABLE bool]
             [STORED bool]
             [USER bool]
             [CONSTANT]
             [FINAL])
```

**examples**

```c++
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

```