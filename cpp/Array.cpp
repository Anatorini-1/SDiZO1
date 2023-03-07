//
// Created by Marcin on 07.03.2023.
//

#include "../headers/Array.h"
#include <iostream>
bool Array::removeLast() {
    if(size < 1) return false;
    int* newData = new int[size-1];
    for(int i=0;i<size-1;i++)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    size--;
    return true;
}


Array::Array() {
    this -> size = 0;
    this -> data = new int[0];
}

int Array::get(int index){
    if(index >= this-> size || index<0) throw;
    return this -> data[index];
}

bool Array::add(int element){
        int* newData = new int[size+1];
        for(int i=0;i<size;i++)
            newData[i] = data[i];
        newData[size] = element;
        delete[] data;
        data = newData;
        size++;
        return true;
}

int Array::find(int value) {
    for(int i=0;i<this -> size; i++){
        if(this -> data[i] == value) return i;
    }
    return -1;
}

Array::~Array() {
    delete[] this -> data;
}

bool Array::removeFirst() {
    if(this -> size < 1) return false;
    int* newData = new int[size-1];
    for(int i=1;i<size;i++){
        newData[i-1] = data[i];
    }
    delete[] data;
    this -> data = newData;
    size--;
    return true;
}

bool Array::remove(int index) {
    if(index >= size) return false;
    int* newData = new int[size-1];
    for(int i=0;i<index;i++)
        newData[i] = data[i];
    for(int i=index+1;i<size;i++)
        newData[i-1] = data[i];
    delete[] data;
    data = newData;
    size--;
    return true;
}

bool Array::addAt(int index, int element) {
    int newSize = index > size+1 ? index+1 : size+1;
    int* newData = new int[newSize];
    for(int i=0;i<size && i<index;i++){
        newData[i] = data[i];
    }
    newData[index] = element;
    for(int i=index;i<newSize && i<size;i++){
        newData[i+1] = data[i];
    }
    size = newSize;
    delete[] data;
    data = newData;
    return true;

}

bool Array::addFirst(int element) {
    int* newData = new int[size+1];
    newData[0] = element;
    for(int i=0;i<size;i++)
        newData[i+1] = data[i];
    delete[] data;
    data = newData;
    size++;
    return true;
}

void Array::print() {
    std::cout << '[';
    for(int i=0;i<size-1;i++)
        std::cout << data[i] <<',';
    if(size >0) std::cout << data[size-1];
    std::cout << "]\n";
    return;
}
