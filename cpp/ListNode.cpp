//
// Created by Marcin on 07.03.2023.
//

#include "../headers/ListNode.h"

ListNode::ListNode() {
    this -> val = 0;
    this -> next = nullptr;
    this -> previous = nullptr;
}

ListNode::~ListNode() {

}

ListNode::ListNode(int v, ListNode * prev, ListNode * next) {
    this -> val = v;
    this -> previous = prev;
    this -> next = next;
}


