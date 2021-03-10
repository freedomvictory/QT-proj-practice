# QT Event 


## 常用事件处理方式 

- 重新实现部件的PaintEvent()、mousePressEvent() 等事件处理函数
- 重新实现部件的Event()  
- 在对象上安装事件过滤器以截取其他部件的事件 

## 重新实现keyPressEvent例子 

```c++

//.H
#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = 0);
    bool event(QEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);
};
//CPP
MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit (parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{

    qDebug() << tr("myLineEdit keyboard press Event!");
    QLineEdit::keyPressEvent(event);
    event->ignore();

}

class MyWidget : public QWidget 
{
    /*
    ....
    */
private:
    MyLineEdit *lineedit; 
}

```

**NOTE** 

`keyPressEvent()`函数中， 执行默认的 ` QLineEdit::keyPressEvent(event)`; 目的是为了让按键时，`QlineEdit` 控件可以显示 文字 

`event->ignore()` 忽略事件，事件会被传递到父窗口相应处理函数 

**事件传递顺序：** 先传递给焦点所在的窗口部件，如果该部件忽略事件，然后再传递到父窗口部件的 `event()`  


## 事件过滤器例子 


```c++
//主窗体
mywidget::mywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mywidget)
{
    ui->setupUi(this);
    m_lineEdit = new MyLineEdit(this);
    m_lineEdit->move(100, 100);
    //子部件要安装事件过滤器
    m_lineEdit->installEventFilter(this);
}

void mywidget::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << tr("Mywidget key press event!");
}

bool mywidget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == m_lineEdit)
    {
        if(event->type() == QEvent::KeyPress)
            qDebug() << tr("mywidget's event filter");
    }
    return QWidget::eventFilter(obj, event);


//自定义部件 
MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit (parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    /*
    qDebug() << tr("myLineEdit keyboard press Event!");
    QLineEdit::keyPressEvent(event);
    event->ignore();
    */
}

bool MyLineEdit::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
        qDebug() << tr("MyLineEdit's event() function called");

    return QLineEdit::event(event);
}


```


**事件传递顺序：** 事件过滤器要优先于事件处理函数。本来事件要从发送方直接发送到接收方，但是另外一个对象的事件过滤器，将事件做了拦截。

`父窗口事件过滤器 --> 焦点部件的 `event()` 函数 --> 焦点部件的事件处理函数 `

## 键盘事件 

`QKeyEvent::isAutoRepeat()`

判断按键是否重复，也就是是否长按。 如果是长按就返回`true`。 否则为`false`



```c++ 
void keyTest::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_M)
            setWindowState(Qt::WindowMaximized);
    }
    else QWidget::keyPressEvent(event);
}
```

## 定时器事件 


```c++ 
void timerEvent(QTimerEvent *event)
``` 

这个函数集中处理所有的定时器事件 


```c++
QTimer *timer = new QTimer(this);
connect(timer, &QTimer::timeout, this, &Widget::timerUpdate);

void Widget::timerUpdate()
{
    //TODO 

}
```
timerUpdate 函数在`timer` 对应的定时器实例，定时溢出后，会触发。


## 事件过滤器与事件的发送 

```c++
book eventFilter(QObject *obj, QEvent *event);
```

这个函数由自定义的窗口类或其他类 实现。 以处理其他部件的事件。 

```c++
ui->textEdit->installEventFilter(this);
ui->spinBox->installEventFilter(this);
```
但是在进行处理之前，必须给相应的部件安装事件过滤器 



## 事件的发送顺序

一个事件从发送方发送到接收方，会调用 `QCoreApplication::notify()`, 这个函数会调用下面的函数，完成其主要的功能。所以我们得到。

事件发送顺序如下 
1. 发送至应用级别的事件过滤器 
2. 发送至接收者的事件过滤器 
3. 发送至接收者的event 函数 





```cpp
bool QCoreApplicationPrivate::notify_helper(QObject *receiver, QEvent * event)
{
    // send to all application event filters (only does anything in the main thread)
    if (QCoreApplication::self
            && receiver->d_func()->threadData->thread == mainThread()
            && QCoreApplication::self->d_func()->sendThroughApplicationEventFilters(receiver, event))
        return true;
    // send to all receiver event filters
    if (sendThroughObjectEventFilters(receiver, event))
        return true;
    // deliver the event
    return receiver->event(event);
}
```


## 自定义事件 


介绍：
    自定义事件，也就是要子类化 `QEvent` ,一次来实现自己的事件类型，实现对象间通信

步骤： 

1. 继承`QEvent` 
2. 定义事件类型 (`registerEventType()`)
3. 在发出通知类或方法中，发出事件 (用 `SendEvent()` 或 `postEvent()`)
4. 在接收通知类或方法中，接收事件（重新实现 `QObject::event()`）

*example*

```c++
class ErrorEvent : public QEvent 
{
public:
    ErrorEvent(int err, const char* desc);
    int errorCode() const {return m_iError}; 
    QString errorDescription() const {return m_strError}; 
    static Type eventType(); 
protected:
    static Type m_evType; 
    int m_iError; 
    QString m_strError; 
}
//构造函数
QEvent:Type ErrorEvent::m_evType = QEvent::None;
ErrorEvent::ErrorEvent(int err, const char * desc)
    :QEvent(eventType()), m_iError(err), m_strError(desc)
{
    
}
//获取事件类型 
QEvent::Type ErrorEvent::eventType() 
{
    if(m_evType == QEVENT::None)
        m_evType = (QEvent::Type)registerEventType();
    return m_evType; 
}

/*发送方
*/
ErrorEvent* errorEvent = new ErrorEvent(1, "argument is not illegal");
Receiver *receiver = ...  //信号接收者
QCoreApplication::postEvent(receiver, errorEvent);

/*接收方*/
class Receiver:public QObject
{
    Q_OBJECT
    //.....
    //.....

}
bool Receiver::event(QEvent *event)
{
    if(event->type() == ErrorEvent::eventType())
    {
        event->accept();
        ErrorEvent *ee = (ErrorEvent *)event; 
        if(ee->errorCode() == 0)
        {
            //some other code 
        }
        else 
        {
            //do something 
        }
    }
}
```

### `postEvent` 和 `sendEvent` 的区别 

- `sendEvent` <br/>

    是阻塞的,调用时直到对方处理完成后，才会返回。不是线程安全的

- `postEvent` <br/>
    是非阻塞的，是异步执行的，调用完成后立即返回。并且是线程安全的。  



### `event->ignore()` 和 `event->accept()` 理解


- `event->ignore()`

指示该事件对于此控件来说，不想要了。此种情况下，会将该事件发给该控件的父部件 

- `event->accept()`

指示该事件对于此控件来说是想要的。 

