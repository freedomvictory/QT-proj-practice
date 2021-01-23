# QByteArray  


# append(const QByteArray &ba)

append the byte array `ba` onto the end of this byte array .

**NOTE:** 
`QByteArray` is an `implicitly shared` class, Consequently,  if you append to an empty byte array, then the byte array will just share the data held in `ba`. in this case , on copying of data is done, taking `constant time`. If a shared instance instance is modified, it will be copied(copy-on-write), taking `linear time`


# convert a bin array to QByteArray  


```c++
QByteArray expect_f("\x00\x00\x10\x40", 4);
```

# 使用 `QByteArray` 大坑 

- `QByteArray &QByteArray::setRawData(const char *data, uint size)`

这个方法用来设置一个`ByteArray` 的原始数据。参数 `data` 指针指向的内存，将有这个 `ByteArray` 来托管。

这个函数的问题在于 `data` 参数 

```c++
char data[] = {0xff, 0xfe, 0x80, 0x90}; 
```
针对上述 data 数组， 在 `c++` 中是一个错误。 0xff 是 `int` 类型， 无法强制转换为 `char` 类型. 这就造成了 `setRawData()` 无法传递`char`类型不兼容的二进制序列。
不过使用 
`QByteArray &QByteArray::append(char ch)` 是可以的。 <br/>
参考下面的例子

```c++
quint8 serial_num = 0x05;
quint8 cmdPack[] = {REQ_COMMAND, serial_num, 0x0c, 0x00, 0x06, 0x00, 
',', 0x1c, 0x00, 0x00, 0x00, ',', 0x00, 0x00, 0x20, 0x40 };

QByteArray bytes_cmd;
for(auto val : cmdPack)
{
    bytes_cmd.append(val);
}
```