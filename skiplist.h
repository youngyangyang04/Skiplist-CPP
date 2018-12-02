/* ************************************************************************
> File Name:     skiplist.h
> Author:        sunxiuyang
> Mail:          sunxiuyang04@gmail.com 
> Created Time:  Sun Dec  2 19:04:26 2018
> Description:   
 ************************************************************************/

#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>

//Class template to implement node
template<typename K, typename V> 
class Node {

public:
    
    Node() {} 

    Node(K k, V v, int); 

    ~Node();

    K getKey() const;

    V getValue() const;
    
    // Linear array to hold pointers to next node of different level
    Node<K, V> **forward;

    int nodeLevel;

private:
    K key;
    V value;
};

template<typename K, typename V> 
Node<K, V>::Node(const K k, const V v, int level) {
    std::cout << "test222222"<<std::endl;
    this->key = k;
    this->value = v;
    this->nodeLevel = level; 

    // // level + 1, because array index is from 0 - level
    this->forward = new Node<K, V>*[level+1];
    
	// // Fill forward array with 0(NULL) 
    memset(this->forward, 0, sizeof(Node<K, V>*)*(level+1));
};

template<typename K, typename V> 
Node<K, V>::~Node() {
    delete []forward;
};

template<typename K, typename V> 
K Node<K, V>::getKey() const {
    // return key;
};

template<typename K, typename V> 
V Node<K, V>::getValue() const {
    // return value;
};

// Class template for Skip list
template <typename K, typename V> 
class SkipList {

public: 
    SkipList(int);
    ~SkipList();
    int randomLevel();

private:    
    // Maximum level of the skip list 
    int MAX_LEVEL;

    // current level of skip list 
    int curLevel;

    // pointer to header node 
    Node<K, V> *header;
};
//
template<typename K, typename V> 
SkipList<K, V>::SkipList(int MAX_LEVEL) {

    this->MAX_LEVEL = MAX_LEVEL;
    this->curLevel = 0;

    // create header node and initialize key and value to null
    std::cout << "test111111" << std::endl;
    K k;
    V v;
    this->header = new Node<K, V>(k, v, MAX_LEVEL);
    // this->header = new Node<K, V>();

};

template<typename K, typename V> 
SkipList<K, V>::~SkipList() {
    // delete header;
}

template<typename K, typename V>
int SkipList<K, V>::randomLevel()
{

    int k=1;

    while (rand()%2)

        k++;

    k=(k<MAX_LEVEL)?k:MAX_LEVEL;

    return k;
};
// vim: et tw=100 ts=4 sw=4 cc=120
