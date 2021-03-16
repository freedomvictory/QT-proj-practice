# `QSopedPointer`

## 介绍 

它是作用域指针，功能类似与 `std::unique_ptr`。它独占原始指针对象的持有权。别的对象，不能与它共有受保护的指针。 在一些比较复杂的函数里，有很多分支语句。在函数开头申请的内存，在函数可能退出的所有点，都要加上释放内存的语句。对 `c/c++ ` 程序员，这是一个非常麻烦的事情。使用 `QScopedPointer` 可以极大地简化这个操作。

除此之外，`QScopedPointer` 在初始化时，还可以指定对象的析构函数
参考官方文档 



## 用途

1. PIMPL (pointer to implementation)

    Qt 的一些类，由于比较复杂。 实现和接口是分离的。接口内有一个私有的指针。这个指针指向实现。 这个指针一般是 `QSopedPointer` 类型。

2. 常规的一些操作。

## `example`

```cpp
/*不使用 `QScopedPointer 的情况 ==> 复杂`*/
void myFunction(bool useSubClass)
{
    MyClass *p = useSubClass ? new MyClass() : new MySubClass;
    QIODevice *device = handsOverOwnership();

    if (m_value > 3) {
        delete p;
        delete device;
        return;
    }

    try {
        process(device);
    }
    catch (...) {
        delete p;
        delete device;
        throw;
    }

    delete p;
    delete device;
}
/*使用 `QScopedPointer`的情况 ==> 简单*/
void myFunction(bool useSubClass)
{
    // assuming that MyClass has a virtual destructor
    QScopedPointer<MyClass> p(useSubClass ? new MyClass() : new MySubClass);
    QScopedPointer<QIODevice> device(handsOverOwnership());

    if (m_value > 3)
        return;

    process(device);
}
```



