# QSharedPointer 

## 介绍

`QSharedPointer` 类似与c++ `std::shared_ptr` ,采用引用计数的方式来管理受托管的内存。多个 `QSharedPointer` 对象可以管理同一块原始指针指向的内存。只有当管理内存的所有 `QSharedPointer`变量被销毁后，原始指针指向的内存才会被释放。 它对 `c++` 指针进行了强引用。 


## 使用场景 

当一个对象在多个模块间传递、使用并保证其能够适时地被释放 



