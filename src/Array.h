//
// Created by Marcin on 09.04.2023.
//

#ifndef SDIZO1_ARRAY_H
#define SDIZO1_ARRAY_H

class Array
{
private:
    int* data;
    int len;

public:
    void addFirst(int elem);
    void addLast(int elem);
    void addAtIndex(int index, int elem);
    void delFirst();
    void delLast();
    void delIndex(int index);
    void delValue(int value);
    void fill(int size, int val);
    int find(int val);
    int operator[](int index);
    Array();
    ~Array();
    void print();
};




#endif //SDIZO1_ARRAY_H
