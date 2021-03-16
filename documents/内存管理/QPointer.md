# QPointer 


## 介绍 

`QPointer` 和常规 `c++` 指针的操作基本是相同的。`QPointer` 优势在于，如果指针指向的内存被释放，那么`QPointer` 值会被清零。 这样，我们就可以在使用`QPointer`时，先判断其是否有效。以防止出现未定义的行为。 另外一个问题是 `QPointer` 指向的对象只能是 `QObject` 的派生类。<br/>
另外`QPointer` 支持类型自动转换为 `T*` ,因此你定义的函数，参数如果为 `T*` ,可以传入`QPointer<T>` 类型的参数，没有问题

## 用途

一些人，可能要使用同一个指针指向的对象。当你持有这个对象的引用，可能别人已经将其释放了。此时`QPointer` 就非常有用。

## example

```c++
QPointer<QLabel> label = new QLabel;
label->setText("&Status:");
...
if (label)
    label->show();
```