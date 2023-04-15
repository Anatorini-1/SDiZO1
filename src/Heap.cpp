//
// Created by Marcin on 09.04.2023.
//

#include "Heap.h"
#include <math.h>
#include <iostream>
#include <iomanip>
void Heap::heapify(int index) {
    if(index == 0){
        return;
    }
    int parentIndex = (index - 1) / 2;
    if(data[parentIndex] < data[index]){
        swap(parentIndex, index);
        heapify(parentIndex);
    }

}

void Heap::swap(int index1, int index2) {
    int temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;

}

void Heap::add(int elem) {
    if(len == 0){
        data = new int[1];
        data[0] = elem;
        len++;
    } else {
        int* newData = new int[len + 1];
        for (int i = 0; i < len; i++) {
            newData[i] = data[i];
        }
        newData[len] = elem;
        delete[] data;
        data = newData;
        len++;
        heapify(len - 1);
    }
}

void Heap::del(int val) {
    if(len == 0) return;
    int index = find(val);
    if(index == -1) return;
    if(index != len-1)
        swap(index,len-1);

    int* newData = new int[len-1];
    for(int i=0;i<len-1;i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    len--;
    heapify(index);
    downHeapify(index);
}

int Heap::find(int val) {
    if(len == 0){
        return -1;
    }
    for (int i = 0; i < len; i++) {
        if(data[i] == val){
            return i;
        }
    }
    return -1;

}

Heap::Heap() {
    data = 0;
    len = 0;
}

Heap::~Heap() {
    delete[] data;
}

void Heap::print() {
    for (int i = 0; i < len; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int Heap::parent(int index) {
    if(index == 0){
        return -1;
    }
    return (index - 1) / 2;
}

int Heap::left(int index) {
    return index * 2 + 1;
}

int Heap::right(int index) {
    return index * 2 + 2;
}

void Heap::downHeapify(int index) {
    int leftIndex = left(index);
    int rightIndex = right(index);
    int largest = index;
    if(leftIndex < len && data[leftIndex] > data[largest]){
        largest = leftIndex;
    }
    if(rightIndex < len && data[rightIndex] > data[largest]){
        largest = rightIndex;
    }
    if(largest != index){
        swap(index, largest);
        downHeapify(largest);
    }
}

void Heap::printTree() {
    std::cout << "------------------------"<<std::endl;
    int depth = log2(len) + 1;
    int index = 0;
    for (int i = 1; i <= depth; i++) {
        for (int j = 0; j < pow(2, i - 1) && index < len; j++) {
            std::cout << std::setw(4) << data[index++];
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------"<<std::endl;

}
