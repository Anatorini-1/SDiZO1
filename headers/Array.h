//
// Created by Marcin on 07.03.2023.
//

#ifndef P1_ARRAY_H
#define P1_ARRAY_H


#include "DataStructure.h"

class Array : public DataStructure{
public:
    int get(int);
    bool add(int);
    bool addFirst(int);
    bool addAt(int,int);
    bool remove(int);
    bool removeFirst();
    bool removeLast();
    int find(int);
    void print();
    Array();
    ~Array();
private:
    int* data;
    int size;
};


#endif //P1_ARRAY_H
