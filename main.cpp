/* ************************************************************************
> File Name:     main.cpp
> Author:        sunxiuyang
> Mail:          sunxiuyang04@gmail.com 
> Created Time:  Sun Dec  2 20:21:41 2018
> Description:   
 ************************************************************************/
#include <iostream>
#include "skiplist.h"
#define FILE_PATH "./store/dumpFile"

int main() {
    // 在这里为什么要手工传，因为不用类型的 k，v 初始化的参数是不一样的。例如string，就不能把
    // 这里还是要改成 初始化 三个参数，要不然去header 上的值容易崩， 也不用改，内部分装好。不回取
    SkipList<int, std::string> skipList(6);
	skipList.insertElement(3, "a"); 
	skipList.insertElement(6, "b"); 
	skipList.insertElement(7, "c"); 
	skipList.insertElement(9, "sun"); 
	skipList.insertElement(12, "xiu"); 
	skipList.insertElement(19, "yang"); 

    skipList.dumpFile();

    std::string path = "./store/dumpFile";
    skipList.loadFile(path);

    skipList.searchElement(9);
    skipList.searchElement(18);


    skipList.displayList();

    skipList.deleteElement(3);

    skipList.displayList();
}
