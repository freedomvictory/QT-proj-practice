# QT Event 


## 常用事件处理方式 

- 重新实现部件的PaintEvent()、mousePressEvent() 等事件处理函数 
- 在对象上安装事件过滤器

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

```

**NOTE** 

`keyPressEvent()`函数中， 执行默认的 ` QLineEdit::keyPressEvent(event)`; 目的是为了让按键时，`QlineEdit` 控件可以显示 文字 

`event->ignore()` 忽略事件，事件会被传递到父窗口相应处理函数 

**事件传递顺序：** 先传递给焦点所在的窗口部件，如果该部件忽略事件，然后再传递到父窗口部件 


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

}

```


**事件传递顺序：** 事件过滤器要优先于事件处理函数 .

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

