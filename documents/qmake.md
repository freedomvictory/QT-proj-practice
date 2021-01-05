# QMAKE 

## pro 文件介绍 


pro文件，即是项目工程文件。用来指定项目的源文件、头文件。描述如何构建，以及插件和库的相关信息。 


## 语法介绍 

- 注释 

```
# Today is a good day 
# I like reading 
```

- 组件选择 

```
QT += core gui 
```
这用来指明，我们的项目需要 `QtGui` 和 `QtCore` 两个模块 


- 目标文件名 

```
TARGET = HelloWorld 
```

用来设置项目的目标文件名 


- 模板 

```
TEMPLATE = app 
```

`TEMPLATE` 变量用来指定项目的构建类型。如果没有在项目中指定这个变量， 它默认为 app .<br/>
目前 `qmake` 支持下列模板 

```
app : 应用
lib : 构建动态库或静态库 
subdirs : 子目录项目 
vcapp : visual studio 项目文件
vclib : visual studio lib 项目文件 
vcsubdirs : visual studio 解决方案文件。包含每个子目录对应的项目文件 
```

- 指定源文件和头文件 

```
SOURCES += main.cpp \
    mainwindow.cpp\
    widget.cpp 
HEADERS += mainwindow.h 
```

- 指定头文件路径 

```
INCLUDEPATH += e:/protobuf-2.0.3/src
```

- 指定库与库文件路径 

```
#Linux like 
LIBS += -L/usr/local/lib -lmath -L/usr/lib -lz 

#windows
LIBS += -Le:/vlc-1.11/sdk/lib -lvlccore 
```

- 定义宏 

```
DEFINES += LIVE_TEST
DEFINES += DEBUG_CONNECTION 
```
