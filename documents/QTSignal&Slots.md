# QT Signal and Slots 


## Singal and Slots instruction 

- 信号：

    当一个特殊的事情发生时便可以发射一个信号。 
- 槽：

    就是一个函数，它在信号发射后被调用来响应这个信号 


## Connect() function 
```c++
[static] QMetaObject::Connection QObject::connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
```

**参数说明:** 

- `sender` 
    发送方 
- `signal`
    发送信号
- `receiver`
    接受方
- `method`
    槽

- `type` 
    连接方式。默认为`AutoConnection`


```c++
Qt::AutoConnection
Qt::DirectConnection
Qt::QueuedConnection
Qt::BlockingQueuedConnection
Qt::UniqueConnection
```


**注意事项** 

1. 需要继承自`QObject`
2. 在类声明的最开始处添加`Q_OBJECT` 宏 
3. 槽中参数的类型要和信号参数的类型相对应，且不能比信号的参数多。 
4. 信号只用声明，没有定义，且返回值为`void`类型

## 信号和槽自动关联 

`on + objname + 信号名称`

```
void myDialog::on_pushButton_clicked()
{
    int value = ui->spinBox->value();
    emit dlgReturn(value);
    close();
}
``` 
不需调用 `connect `, 默认已经在 `ui->setupUI()` 配置完成 

## 信号和槽断开关联 
```c++
[static] bool QObject::disconnect(const QObject *sender, const char *signal, const QObject *receiver, const char *method)
```


