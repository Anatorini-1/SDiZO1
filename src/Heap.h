//
// Created by Marcin on 09.04.2023.
//

#ifndef SDIZO1_HEAP_H
#define SDIZO1_HEAP_H
#include <string>
/*We will assume a max-heap*/
class Heap {
private:
    int* data;
    int len;
    void heapify(int index);
    void downHeapify(int index);
    void swap(int index1, int index2);
    int parent(int index);
    int left(int index);
    int right(int index);
public:
    void add(int elem);
    void del(int val);
    int find(int val);
    Heap();
    ~Heap();
    void print();
    void printTree();
    void loadFromFile(std::string path);
};


#endif //SDIZO1_HEAP_H
