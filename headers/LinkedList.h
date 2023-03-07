//
// Created by Marcin on 07.03.2023.
//

#ifndef P1_LINKEDLIST_H
#define P1_LINKEDLIST_H


#include "DataStructure.h"
#include "ListNode.h"

class LinkedList : DataStructure{
public:
    int get(int) override;
    bool add(int) override;
    bool addFirst(int);
    bool addAt(int index,int value);
    bool addLast(int);
    bool remove(int) override;
    bool removeFirst();
    bool removeLast();
    int find(int) override;
    void print() override;
    LinkedList();
    ~LinkedList();
private:
    ListNode* head;
    ListNode* tail;
};


#endif //P1_LINKEDLIST_H
