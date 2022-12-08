👉 推荐 [Gitee同步](https://gitee.com/programmercarl/skiplist)

> 版权申明： 本项目为我（[程序员Carl](https://github.com/youngyangyang04)）的原创。引用本项目文章请注明出处，例如：转自 https://github.com/youngyangyang04/Skiplist-CPP。
> 发现恶意抄袭或搬运，会动用法律武器维护自己的权益。让我们一起维护一个良好的技术创作环境！

# [English Version](./README-en.md)

# KV存储引擎

众所周知，非关系型数据库redis，以及levedb，rockdb其核心存储引擎的数据结构就是跳表。

本项目就是基于跳表实现的轻量级键值型存储引擎，使用C++实现。插入数据、删除数据、查询数据、数据展示、数据落盘、文件加载数据，以及数据库大小显示。

在随机写读情况下，该项目每秒可处理啊请求数（QPS）: 24.39w，每秒可处理读请求数（QPS）: 18.41w

# 项目中文件

* main.cpp 包含skiplist.h使用跳表进行数据操作
* skiplist.h 跳表核心实现
* README.md 中文介绍    
* README-en.md 英文介绍       
* bin 生成可执行文件目录 
* makefile 编译脚本
* store 数据落盘的文件存放在这个文件夹 
* stress_test_start.sh 压力测试脚本
* LICENSE 使用协议

# 提供接口

* insertElement（插入数据）
* deleteElement（删除数据）
* searchElement（查询数据）
* displayList（展示已存数据）
* dumpFile（数据落盘）
* loadFile（加载数据）
* size（返回数据规模）


# 存储引擎数据表现

## 插入操作

跳表树高：18 

采用随机插入数据测试：


|插入数据规模（万条） |耗时（秒） | 
|---|---|
|10 |0.316763 |
|50 |1.86778 |
|100 |4.10648 |


每秒可处理写请求数（QPS）: 24.39w

## 取数据操作

|取数据规模（万条） |耗时（秒） | 
|---|---|
|10|0.47148 |10|
|50|2.56373 |50|
|100|5.43204 |100|

每秒可处理读请求数（QPS）: 18.41w

# 项目运行方式

```
make            // complie demo main.cpp
./bin/main      // run 
```

如果想自己写程序使用这个kv存储引擎，只需要在你的CPP文件中include skiplist.h 就可以了。

可以运行如下脚本测试kv存储引擎的性能（当然你可以根据自己的需求进行修改）

```
sh stress_test_start.sh 
```

# 待优化 

* delete的时候没有释放内存
* 压力测试并不是全自动的
* 跳表的key用int型，如果使用其他类型需要自定义比较函数，当然把这块抽象出来更好
* 如果再加上一致性协议，例如raft就构成了分布式存储，再启动一个http server就可以对外提供分布式存储服务了

# 关于作者

大家好，我是程序员Carl，[《代码随想录》](https://programmercarl.com/other/publish.html)作者，哈工大师兄，先后在腾讯和百度从事分布式技术研发。

* [代码随想录网站](https://programmercarl.com)
* [代码随想录Github](https://github.com/youngyangyang04/leetcode-master)
* [代码随想录算法公开课](https://www.bilibili.com/video/BV1fA4y1o715)


