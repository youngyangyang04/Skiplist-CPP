# Skiplist-CPP

 A tiny KV storage based on skiplist written in C++ language

# interface

* insertElement
* deleteElement 
* searchElement
* displayList
* dumpFile 
* loadFile

# performance data  
## insert

skiplist tree high:18
insert random key

|insert element num (w) | timecost (s)  |
|---|---|
|10 |0.316763 |
|50 |1.86778 |
|100 |4.10648 |

qps: 24.39w

## get

|search element (w) |timecost (s) |skiplist size (w)|
|---|---| --- |
|10|0.47148 |10|
|50|2.56373 |50|
|100|5.43204 |100|

qps:18.41w


# code coverage report 

gtest and  lcov

[](file:///Users/sunxiuyang/Downloads/tmp/result/home/users/sunxiuyang/workspace/baidu/personal-code/sunxiuyang/index.html)

how to getcoverage report  

```
lcov -d . -t 'skiplist_test' -o 'skiplist_test.info' -b . -c  

genhtml -o result skiplist_test.info
```

# load 
insert the data from file

[Skip List](https://www.geeksforgeeks.org/skip-list-set-3-searching-deletion/)
[fstream](http://www.cplusplus.com/doc/tutorial/files/)
[SkipListPro](https://github.com/HiWong/SkipListPro)
[skiplist](https://github.com/greensky00/skiplist)

# Todo 


