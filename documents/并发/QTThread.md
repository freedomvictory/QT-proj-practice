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

**注意：**<br/> 一个对象要移动到另一个线程。 那么这个对象包含的部件对象(`QObject`派生类实例)，特别是指针对象，一定要是这个对象的孩子。否则这个部件对象，是无法移动到新线程的。(可能是一个 `QTimer`) ,要特别注意 


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


线程间通信方式，目前分为2种。非阻塞方式的通信，阻塞方式的通信 

目前Qt可以通过信号与槽或者事件发布，实现非阻塞方式，跨线程通信 



`QApplication::PostEvent` 用于发送事件给其他线程内的对象 

简言之就是发送线程，调用 `QApplication::PostEvent` 发布事件到接收线程的接收者对象。 由接收者对象在事件处理函数中，做事件的处理。 由此实现来线程间的非阻塞通信。 

实例请参考 安老师写的 `doorbell` 的例子
`/cygdrive/e/Documents/code/c++/Qt-proj-practice/UI-PROJ/smallExamples/doorbell`










## `QThread` Read Write Lock 


如果读的那一方 和 写的那一方 同时等待锁时，写的那一方优先。简而言之 写的那一方有更高的优先级。 

多线程可以同时读，但是写的时候，只能一个线程去写 

写的那一方何时才能使用锁 
    任何一个线程没有占用读写锁。 不管是读还是写 

读的那一方何时才能使用锁 
    任何一个线程没有占用读写锁用于写。 
    如果有线程占用读写锁用于读，此时读的线程是可以再次可以获得锁，用于读的 （前提是没有写的那一方与它抢占锁）


## `QSemphore`

信号量可用于管理多个相同类型的资源。 比方说是一个循环Buffer. A线程要去写buffer, B线程要去读A写了之后的buffer的内容. A和B类似于生产者和消费者。 buffer是一个字节数组。 假定字节数组中每个 `byte` 都是一个资源的话。 `Semphore` 可用于计算buffer 中 `byte` 资源的个数。
A线程和B线程，会操作信号量，申请资源和释放资源。 

请参考示例

[semphore example](https://doc.qt.io/qt-5/qtcore-threads-semaphores-example.html)




## `QWaitCondition`

条件变量。 多个线程之间并行运行。一个线程与审查某些条件，其他线程等待条件满足，做一些事情。 第一个线程条件满足时，可发送信号给其他线程，其他线程不再阻塞可继续执行。 这种情况下，可以用条件变量来实现。 

请参考实例 

[wait condition example ](https://doc.qt.io/archives/qt-5.9/qtcore-threads-waitconditions-example.html)










