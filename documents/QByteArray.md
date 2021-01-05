# QByteArray  


# append(const QByteArray &ba)

append the byte array `ba` onto the end of this byte array .

**NOTE:** 
`QByteArray` is an `implicitly shared` class, Consequently,  if you append to an empty byte array, then the byte array will just share the data held in `ba`. in this case , on copying of data is done, taking `constant time`. If a shared instance instance is modified, it will be copied(copy-on-write), taking `linear time`


# convert a bin array to QByteArray  


```c++
QByteArray expect_f("\x00\x00\x10\x40", 4);
```