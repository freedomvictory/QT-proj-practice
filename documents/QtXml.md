# `QtXml`

## `xml stream` 的使用 



### `xml stream reader` 

xml stream reader 的处理方式，就是在一个循环中，一个个读取元素。根据读取元素名称和 `TokenType` 进行处理。读取文本可以调用 `readText()` 方法 

参考实例 `QXmlStream Bookmarks Example`



- `readNextStartElement()`
    读取当前元素内的下一个元素。 
    当前元素指的是: 一个最近的元素，这个元素，`start element token`已经解码，但 `end element token` 还未解码。如果解析器已经到达了一个元素的 `end element token` , 那么当前元素将会变成这个元素的父元素。 

- `tokenString()`

    获取当前 `token`
    token 的 类型 ，可通过查看 `enum QXmlStreamReader::TokenType` 来获得。 

    TestXmlReader.cpp 中 `TestXML::test__tokenType()` 测试大多数的`TokenType` 





### `xml stream writer` 


`xml stream writer` 的处理方式是便捷的。 调用 `QXmlStreamWriter::writeStartDocument()` ,这个函数会自动添加首行的XML说明。添加元素可以使用 `writeStartElement()`,之后可以进行元素的属性添加和文本添加。 添加完成后，记得调用 `writeEndElement` 关闭打开的元素。可以连续调用 `writeStartElement` ,相当于元素嵌套。每一个元素结束后，都应该调用`writeEndElement` ,使用 `writeEndDocument()` 用来完成文档的写入 




