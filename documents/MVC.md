# MVC 即 模型视图控制器编程 



## MVC 架构 


![](https://doc.qt.io/qt-5/images/modelview-overview.png)


### 模型 

基于 `QAbstractItemModel` 编写的子类。这个类定义了一个接口，可以供视图和委托来访问数据。

**QT 提供了一些现成的模型，来处理数据项**

  - `QStringListModel`  存储一个简单的`QString` 项目列表

  - `QStandardItemModel`  管理复杂的树型结构数据项

  - `QFileSystemModel`  提供了本地文件系统中文件和目录的信息

  - `QSqlQueryModel` 和 `QSqlTableModel` 和 `QsqlRelationalTableModel`
用来访问数据库 


### 视图

抽象基类 `QAbstractItemView`

- `QListView`

- `QTreeView`




### 委托

抽象基类 `QAbstractItemDelegate`


- `QStyledItemDelegate`

    带QT样式表 

- `QItemDelegate`

    不带 
