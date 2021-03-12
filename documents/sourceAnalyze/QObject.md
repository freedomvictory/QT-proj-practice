# QObject 源码剖析 

## PIMPL 

[stackoverflow good answer](https://stackoverflow.com/questions/25250171/how-to-use-the-qts-pimpl-idiom)

    pointer to implement 


在QObject 的实现代码中，有一个 `QObject Private`, 它是 QObject 的内部实现。`QObject` 只是接口部分 
QObject 内的有一个指针，指向 `QObjectPrivate` 类型的对象。因此这称之为`PIML`

Qt 提供了一些宏，服务与`PIML`，帮助简化 `pointer to implement` 的实现.以用来封装大型接口 


- `Q_DECLARE_PRIVATE `

- `Q_PRIVATE_SLOT`

- `Q_D`

- `Q_Q`

- `Q_DECLARE_PUBLIC`

- `Q_DISABLE_COPY`


请参考 `stackoverflow ` 上面的说明 



**疑问:**
    针对于接口类，这个类前面有private 类的前置声明，那么接口类的构造函数，析构和赋值都得是 not inline,必须定义在cpp file 中，这是为什么呢？ 

    参考 QScopedPoiter 帮助手册 `Forward Declared Pointers` 部分



2.继续查看 ~Object() 中 `SharedRefCount` 的代码 


