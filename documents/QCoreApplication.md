
# QCoreApplication 


- `void QCoreApplication::postEvent(QObject *receiver, QEvent *event, int priority = Qt::NormalEventPriority)`

发布事件给指定接收者。用于跨线程非阻塞通信。 这个函数调用后，会将这个事件放到事件队列里，等待处理。事件队列的执行顺序是按照其优先级，优先级高的先执行。

- `bool QCoreApplication::sendEvent(QObject *receiver, QEvent *event)`

直接发布事件给接收者，一般用于同一个线程内的对象通信 

