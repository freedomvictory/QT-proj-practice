# QMdiArea 

## 介绍 

`QMdiArea` 窗体提供了一个区域供MDI(多文档界面)窗口展示，`QMdiArea` 就像一个多文档窗口管理器一样。例如它绘制很多窗口，并且安排它们的布局。`QMdiArea` 通常作为`QMainWindow`的中心窗体，创建`MDI` 应用 
```c++
QMainWindow *mainWindow = new QMainWindow;
mainWindow->setCentralWidget(mdiArea);
```
`QMdiSubWindow`实例 是`QMdiArea`的子窗口。当键盘焦点集中到一个子窗口时，这个窗口会变为活动窗口，当活动窗口改变时，`MDI` 发送`subWindowActivated()` 信号。通过`activeSubWindow()` 可获取当前的活动子窗口 

使用`subWindowList()` 函数，可以返回所有子窗口的列表 
使用`activateNextSubWindow()` 可以使下一个子窗口处于活动状态，`actviePreviousSubWindow` 可以使前一个子窗口处于活动状态。
