# Skiplist-CPP

 A tiny KV storage based on skiplist written in C++ language

# interface

* insertElement
* deleteElement 
* searchElement
* displayList
* dumpFile 
* loadFile
* size

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

# USAGE

Just include skiplist.h in your code

```
make            // complie demo main.cpp
./bin/main      // run 
```

Test performance data 

```
sh stress_test_start.sh 
```


# Todo 

* stress test is not auto

# License

This library is licensed under GPL-3.0 License. See LICENSE for details.
