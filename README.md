# Skiplist-CPP

 A tiny KV storage based on skiplist written in C++ language

# code style

* lower camel case

# interface

* insertElement
* deleteElement 
* searchElement
* displayList
* dumpFile 
* loadFile

# performance data  

skiplist tree high:12

|insertElement num (w) | timecost (s)  | 
|---|---|
|10 |1.20767 |
|50 |5.27127 | 
|100 |10.8861 | 

qps: 10w


|searchElement (w) |timecost (s) | 
|---|---|
|10|1.66063 |
|50|8.83304 |
|100|16.8302 |

qps:7W


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



