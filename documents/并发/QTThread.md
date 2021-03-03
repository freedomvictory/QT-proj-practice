# QTThread 

## 介绍 

是一个平台无关的管理线程的类。提供了API ，可以开始和结束线程。一般我们选择 继承 `QThread` 定义自己的 `QThread` 或是实现自己的 `worker` 调用 `moveToThread()` 将 worker 移动到一个新建的`Thread`进行处理 

## 使用 `QThread` 注意事项 

要区分线程对象、线程

- 线程:对象指的是 子类化`QThread`,或未子类化 `QThread` 的对象。它一般由一个旧有的线程去创建这个对象。可能是主线程，也可能是工作线程。创建线程对象的目的是启动一个新线程。 
- 线程:cpu调度的最小单位。cpu保证其可以并行执行。 

假设子类化一个 `QThread`。 你定义了`run()` 函数，还有一些槽。那么当你在主线程当中实例化 `QThread`时。 此时就创建了一个线程对象。 当你调用 `start()` 方法时，线程才真正启动起来。

并且注意一个问题。根据线程关联性。你子类化 `QThread`，`run()`可以在新线程中执行，但是你自己定义的槽，并不会在新的线程当中执行。这是因为 `线程对象`属于旧有的线程。因此你在新线程中，无法使用`线程对象`。<br/>
你可以通过在`run()` 中定义对象来使用其信号和槽。这个对象称之为工作对象。 也可以使用 `worker object`， 调用 `moveToThread()` 方法，将`worker object` 的持有者，更换为新线程，就可以使用其信号和槽。  

## 线程关联 

所谓线程关联，就是一个线程所持有的对象，要想使用的话。必须关联到这个新`Thread`上 。也就是说这个对象必须在使用线程下创建和使用。如果不这样做的话，将会出现错误。 

如下实例，我们有一个`MyThread` ,这个Thread 运行的时候，会启动一个定时器。 `MyThread` 中有一个私有变量 `m_timer`, 在`MyThread` 构造函数当中，我们必须用 `m_timer.moveToThread()` 来吧 `m_timer` 变量，绑定到这个线程上。 如果不这样做，运行时将会报如下错误。 
```
QWARN  : TestThread::runThread() QObject::startTimer: Timers canot be started from another thread
```

```c++
class MyThread: public QThread 
{
public:
    explicit MyThread();
protected:
    void run() override;
private:
    QTimer m_timer; 
};

MyThread::MyThread()
{
    //m_timer need to move to this thread!!!
    //Otherwise it will report an error 
    m_timer.moveToThread(this); 
    connect(&m_timer, &QTimer::timeout, [](){
        qDebug() << "timer timeout!";
    });
}

void MyThread::run()
{
    m_timer.start(1000);
    QThread::run(); 
}
//测试类 
class TestThread: public QObject 
{
    Q_OBJECT
private slots:
    void runThread(); 
};
//测试方法
void TestThread::runThread()
{
    MyThread a; 
    a.start(); 
    QTest::qWait(3000);
}
```

## 使用QThread 如何优雅的释放内存


一个`QThread` 要释放内存。要有2个步骤。 第一 `run()` 结束。 第二 释放 `QThread` 使用的对象 

如果 `run()` 函数中有 `exec()` 调用。 这意味着工作线程当中有事件循环。 要想结束事件循环，调用 `QThread::quit()`，此时`run()` 便会结束
那么如何释放 `QThread` 使用的对象。一般是将 `QThread` 的 `finished` 信号与 `QObject::deleteLater` 连接 。你可能需要，将`finished` 信号连接到每一个你的线程中使用的对象。 也可以使用其他方法释放对象，如使用`smart pointer`, 当 `run()` 函数退出时，没有任何对象使用 `smart pointer`, `smart pointer` 指向的对象便会自动销毁 <br/>
使用 `QThread::wait()` 方法，可以阻塞直到线程结束。 类似于 linux  `pthread_join()` 函数。 


参考 `TESTS/QThread/threadWorker.cpp`  理解 线程结束时，信号和槽的执行顺序 


https://mp.weixin.qq.com/s/CPS68Vo-lUztAF5tbiDIKg
## `QThread` 实现线程间通信

