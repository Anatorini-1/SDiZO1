//
// Created by Marcin on 07.03.2023.
//

#ifndef P1_LINKEDLIST_H
#define P1_LINKEDLIST_H


#include "DataStructure.h"
#include "ListNode.h"

class LinkedList : DataStructure{
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
    LinkedList();
    ~LinkedList();
private:
    ListNode* head;

};


#endif //P1_LINKEDLIST_H
