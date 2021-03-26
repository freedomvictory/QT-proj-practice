# Model/View 

参考 `https://doc.qt.io/archives/qt-5.9/modelview.html#1-introduction`

## 1. 介绍 

### 1.1 `MVC` 是什么 

![](https://doc.qt.io/qt-5/images/modelview-overview.png)

即`Model view controller`，模型、视图和控制器。 是图形化程序的一种设计模式。它实现了图形化应用的 模型、视图和控制器的分离。模型用于存储数据，视图用于展示界面，控制器用来响应用户输入。 

### 1.2 `Model/View` 相比与标准窗体的优势 

1. 更容易做数据同步 `???` <br/>
    传统的窗体，编辑数据的一方和显示窗体的一方是各持有一份数据的。当编辑数据的一方对数据进行修改，必须通知显示窗体的一方要更新展示的数据。涉及一个复杂的同步过程。`Qt Model/View` 拥有非常方便的接口提供数据同步。

2. 代码不耦合<br/>
3. 更容易编写单元测试 <br/>

### 1.3 `Adapter` 是什么  ???

粗浅理解：<br/>
    是一个桥梁，实现了 `Model` 和 `Form` 之间的连接 

## 2. 构建 `MVC` 示例程序 

### 2.1 子类化 `QAbstractTableModel`

要定义我们自己的`Model` 存储数据和 `View` 交互，我们必须子类化 `QAbStractItemModel` 或是 `QAbstractTableMode` 等。也就是我们必须按照 `Qt` MVC 的规定，正确封装方法和接口 <br/>
对于 `QAbstractTableModel` ，它是 表格模型的基类。要定义我们自己的`Table Model` 必须至少定义以下3个方法

```cpp
int rowCount(const QModelIndex &parent = QModelIndex()) const override ; //获取行数
int columnCount(const QModelIndex &parent = QModelIndex()) const override;  //获取列数 
QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override; //获取指定Index 下的 数据 
```
定义完成上述3个方法。`Model` 可以做到数据的基本展示。 在展示窗体时，`data()` 会频繁调用。用以展示每个单元格的数据，设置背景和字体等。 


### 2.2 `Qt::ItemDataRole`

参考 help 文档 

指示 `item` 数据项的角色类型。





### 2.3 `dataChanged` signal 

这个信号，在`Model` 的方法中，如有数据的改动，应触发此信号 

```cpp
void QAbstractItemModel::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int> ())
```

视图 `View` 在设置 `Model` 时会自动连接此信号到自己的槽里，以实现数据修改时的数据同步。所以，我们需要为`View` 提供好数据改动时的信号。 



### 2.4 set up header data 

重新实现自定义 Model 的 `headerData()` 方法，可以设定数据项的头 


### 2.5 editing data 

使视图能够编辑数据，需要重新实现自定义Model的 `setData()` 和 `flags()` ,`setData()` 用于操作底层数据，并在数据改变时发送 `dataChanged()` 信号。 `flags()` 返回数据项的可编辑标志位 


## 3. 中级主题 

### 3.1 `TreeView`

`TreeView` 是树状的视图。

`QStandItemModel` 可用于存储层级的数据结构。适用于`TreeView`. `QStandItem` 是`Model` 的基本元素。利用 `QStandardItemModel ::invisibleRootItem()` 可获得`Model` 的根元素， 利用 `appendRow()` 可添加子节点到 根节点，或其他二级节点，三级节点， N 级节点上。

### 3.2 selection model 

`selection model` 用户选择的数据模型。 <br/>
`selection model` 可以通过 `TreeView` 或其他`View`的 方法 `selectionModel()` 来获取。`selection model` 含有 `selectionChanged` 信号，可用于通知其他对象，用户选择的数据已经改变。 


### 3.3 delegate 

用于单个特定项目，如一个单元格数据的展示和编辑， 不同于非常规的效果 。
如一个单元格，你想展示一个漂亮的控件。一个特定的图形，编辑也想要不同的效果，那就用委托。 

继承 `**ItemDelegate` 基类，自己实现 `painter()`, `createEditor()`, `setEditorData` 和 `setModelData()` 等方法。 这些方法基本上都是`override`

`https://doc.qt.io/archives/qt-5.9/qtwidgets-itemviews-stardelegate-example.html` 这个例子展示了 `delegate` 的用法 
