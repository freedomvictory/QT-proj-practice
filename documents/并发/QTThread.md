# QTThread 

## 介绍 

是一个平台无关的管理线程的类。提供了API ，可以开始和结束线程。一般我们选择 继承 `QThread` 定义自己的 `QThread` 或是实现自己的 `worker` 调用 `moveToThread()` 将 worker 移动到一个新建的`Thread`进行处理 

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

## `QThread` 实现线程间通信

