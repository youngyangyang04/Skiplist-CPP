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

    SkipList<std::string, std::string> skipList(6);
	skipList.insert_element("1", "a"); 
	skipList.insert_element("3", "b"); 
	skipList.insert_element("7", "c"); 
	skipList.insert_element("8", "sun"); 
	skipList.insert_element("9", "xiu"); 
	skipList.insert_element("19", "yang"); 
	skipList.insert_element("19", "yang"); 
	skipList.insert_element("19", "yang"); 
	skipList.insert_element("19", "yanuuuuuuuuuuuuuuuuuug"); 

    std::cout << "skipList size:" << skipList.size() << std::endl;

    skipList.dump_file();

    // skipList.load_file();

    skipList.search_element("9");
    skipList.search_element("18");


    skipList.display_list();

    skipList.delete_element("3");
    skipList.delete_element("7");

    std::cout << "skipList size:" << skipList.size() << std::endl;

    skipList.display_list();
}
