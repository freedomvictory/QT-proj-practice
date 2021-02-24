# QT SQL 


## 事务操作 

```c++
QSqlDatabase::database().transcation();
QSqlQuery query; 
//转账操作--第一步
bool ok = query.exec("UPDATE accounts SET balance = balance - 100 WHERE id = 1; ");
if(ok)
{
    //转账操作--第二步 
    ok = query.exec("UPDATE accounts SET balance = balance + 100 WHERE id = 2; ");
    if(ok)
        QSqlDatabase::database().commit(); 
    else 
        QSqlDatabase::database().rollback(); 
}
else 
    QSqlDatabase::database().rollback(); 
```

上述事务，把两条`SQL` 语句绑定到一起。 其中一个执行失败，就执行回滚操作，相当与之前执行的`SQL`命令作废。所有都执行成功，才算成功。 

## 使用 `SQL` 模型类 

1. SQL 查询模型 

```cpp
QSqlQueryModel *model = new QSqlQueryModel(this); 
//设定查询语句：执行完的结果会保存到Model里 
model->setQuery("select *from student"); 
QTableView *view = new QTableView(this); 
//为view设置model. 此时会更新视图  
view->setModel(model);
```

你可以将模型用于 `QCombobox` ,`QTableView`, `QListView` 中 

2. SQL表格模型 

提供了更高级的`API` 操作一个 `SQL` 表。不需要了解 `SQL` 语法 
，就可以进行插入，查询，删除等操作。 

```cpp 
QSqlTableModel *model = new QSqlTableModel(this); 
//设置表格
model->setTable("student");
//执行查询 
model->select();
//设置编辑策略  
model->setEditStrategy(QSqlTableModel::OnManualSubmit);
```

参考实例代码 

[sqlmy](tests/QSQL/sqlmy)

3. 关系表格模型 

`QSqlRelationalTableModel` 继承自 `QSqlTableModel` 并对其功能进行了扩展，提供了对外键的支持 

```c++
QSqlRelationTableModel *model = new QSqlRelationTableModel(this);
model->setTable("student");
//在2个表中创建关系 
model->setRelation(2, QSqlRelation("course", "id", "name"));
model->select();
QTableView *view = new QTableView(this);
view->setModel(model);
```

`setRelation()` 中第一个参数为 2， 表示`student` 表的第二个字段作为外键。第二个参数中，`"course"` 表示第二张表名， `"id"` 为第二张表的主键， `"name"` 为要显示的字段。 


- `student` 表

| ID     | NAME  | course|
| ------ |:-----:| -----:|
| 1      | 张明  | 11    |
| 2      | 王华  | 12    |
| 3      | 董倩  | 13    |

- `course` 表 

| ID     | NAME  | 
| ------ |:-----:| 
| 11     | 美术  | 
| 12     | 音乐  | 
| 13     | 化学  |


显示的结果将会是 

| ID     | NAME  | course_name_2|
| ------ |:-----:| ------------:|
| 1      | 张明  | 美术          |
| 2      | 王华  | 音乐          |
| 3      | 董倩  | 化学          |