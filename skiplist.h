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
#include <mutex>
#include <fstream>

#define STORE_FILE "store/dumpFile"

std::mutex mtx;     // mutex for critical section

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
    return key;
};

template<typename K, typename V> 
V Node<K, V>::getValue() const {
    return value;
};

// Class template for Skip list
template <typename K, typename V> 
class SkipList {

public: 
    SkipList(int);
    ~SkipList();
    int randomLevel();
    Node<K, V>* createNode(K, V, int);
    void insertElement(K, V);
    void displayList();
    bool searchElement(K);
    void deleteElement(K);
    void dumpFile();
    void loadFile(std::string& path);

private:    
    // Maximum level of the skip list 
    int MAX_LEVEL;

    // current level of skip list 
    int skipListLevel;

    // pointer to header node 
    Node<K, V> *header;

    std::ofstream fileWriter;
    std::ifstream fileReader;

    void getKeyValueFromString(const std::string& str, std::string& key, std::string& value);

};

// create new node 
template<typename K, typename V>
Node<K, V>* SkipList<K, V>::createNode(const K k, const V v, int level) {
    Node<K, V> *n = new Node<K, V>(k, v, level);
    return n;
}

// Insert given key and value in skip list 
template<typename K, typename V>
void SkipList<K, V>::insertElement(const K key, const V value) {
    mtx.lock();
    
    Node<K, V> *current = this->header;

    // create update array and initialize it 
    // update is array which put node that the node->forward[i] should be operated later
    Node<K, V> *update[MAX_LEVEL+1];
    memset(update, 0, sizeof(Node<K, V>*)*(MAX_LEVEL+1));  

    
    // start form highest level of skip list 
    for(int i = skipListLevel; i >=0; i--) {
        while(current->forward[i] != NULL && current->forward[i]->getKey() < key) 
            current = current->forward[i]; 
        update[i] = current;
    }

    // reached level 0 and forward pointer to right node, which is desired to insert key.
    current = current->forward[0];

    // if current is NULL that means we have reached to end of the level 
    // if current's key is not equal to key that means we have to insert node between update[0] and current node 
    if (current == NULL || current->getKey() != key) {
        
        // Generate a random level for node
        int rLevel = randomLevel();

        // If random level is greater thar skip list's current level, initialize update value with pointer to header
        if (rLevel > skipListLevel) {
            for (int i = skipListLevel+1; i < rLevel+1; i++) {
                update[i] = header;
            }
            skipListLevel = rLevel;
        }

        // create new node with random level generated 
        Node<K, V>* insertedNode = createNode(key, value, rLevel);

        // insert node 
        for (int i = 0; i <= rLevel; i++) {
            insertedNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = insertedNode;
        }

        std::cout << "Successfully inserted key:" << key << ", value:" << value << std::endl;
    }
    mtx.unlock();
}

// Display skip list 
template<typename K, typename V> 
void SkipList<K, V>::displayList() {
    std::cout << "\n*****Skip List*****"<<"\n"; 
    for (int i = 0; i <= skipListLevel; i++) {
        Node<K, V> *node = this->header->forward[i]; 
        std::cout << "Level " << i << ": ";
        while (node != NULL) {
            std::cout << node->getKey() << ":" << node->getValue() << ";";
            node = node->forward[i];
        }
        std::cout << std::endl;
    }
}

// Dump data in memory to file 
template<typename K, typename V> 
void SkipList<K, V>::dumpFile() {
    std::cout << "dumpFile-----------------" << std::endl;
    fileWriter.open(STORE_FILE);
    Node<K, V> *node = this->header->forward[0]; 
    while (node != NULL) {
        fileWriter << node->getKey() << ":" << node->getValue() << ";\n";
        std::cout << node->getKey() << ":" << node->getValue() << ";\n";
        node = node->forward[0];
    }
    fileWriter.flush();
    return ;
}

// Load data from disk
template<typename K, typename V> 
void SkipList<K, V>::loadFile(std::string& path) {
    fileReader.open(path);
    std::cout << "loadFile-----------------" << std::endl;
    std::string line;
    std::string key, value;
    while (getline(fileReader, line)){
        getKeyValueFromString(line, key, value);
        std::cout << "key:" << key << "value:" << value << std::endl;
    }
}

template<typename K, typename V>
void SkipList<K, V>::getKeyValueFromString(const  std::string& str, std::string& key, std::string& value) {
    std::string delimiter = ":";
    key = str.substr(0, str.find(delimiter));
    value = str.substr(str.find(delimiter)+1, str.length());
}

// Delete element from skip list 
template<typename K, typename V> 
void SkipList<K, V>::deleteElement(K key) {

    mtx.lock();

    Node<K, V> *current = this->header; 

    Node<K, V> *update[MAX_LEVEL+1];
    memset(update, 0, sizeof(Node<K, V>*)*(MAX_LEVEL+1));

    // start from highest level of skip list
    for (int i = skipListLevel; i >= 0; i--) {
        while (current->forward[i] !=NULL && current->forward[i]->getKey() < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current != NULL && current->getKey() == key) {
       
        // start for lowest level and delete the current node of each level
        for (int i = 0; i <= skipListLevel; i++) {

            // if at level i, next node is not target node, break the loop.
            if (update[i]->forward[i] != current) 
                break;
            update[i]->forward[i] = current->forward[i];
        }

        // Remove levels which have no elements
        while (skipListLevel > 0 && header->forward[skipListLevel] == 0) 
            skipListLevel --; 

        std::cout << "Successfully deleted key "<< key << std::endl;
    }
    mtx.unlock();
}

// Search for element in skip list 
template<typename K, typename V> 
bool SkipList<K, V>::searchElement(K key) {
    std::cout << "searchElement-----------------" << std::endl;
    
    Node<K, V> *current = header;

    // start from highest level of skip list
    for (int i = skipListLevel; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->getKey() < key) {
            current = current->forward[i];
        }
    }

    //reached level 0 and advance pointer to right node, which we search
    current = current->forward[0];

    // if current node have key equal to searched key, we get it
    if (current and current->getKey() == key) {
        std::cout << "Found key: " << key << ", value: " << current->getValue() << std::endl;
        return true;
    }

    std::cout << "Not Found Key:" << key << std::endl;
    return false;
}

// construct skip list
template<typename K, typename V> 
SkipList<K, V>::SkipList(int MAX_LEVEL) {

    this->MAX_LEVEL = MAX_LEVEL;
    this->skipListLevel = 0;

    // create header node and initialize key and value to null
    std::cout << "test111111" << std::endl;
    K k;
    V v;
    this->header = new Node<K, V>(k, v, MAX_LEVEL);


};

template<typename K, typename V> 
SkipList<K, V>::~SkipList() {
    if (fileWriter.is_open())
        fileWriter.close();
    if (fileReader.is_open())
        fileReader.close();
    delete header;
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
