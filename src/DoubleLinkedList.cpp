//
// Created by Marcin on 09.04.2023.
//

#include "DoubleLinkedList.h"
#include <iostream>
void DoubleLinkedList::addFirst(int elem) {
    if(head == 0){
        head = new Node;
        head->value = elem;
        head->next = 0;
        head->prev = 0;
        tail = head;
    } else {
        Node* temp = new Node;
        temp->value = elem;
        temp->next = head;
        temp->prev = 0;
        head->prev = temp;
        head = temp;
    }
}

void DoubleLinkedList::addLast(int elem) {
    if(head == 0){
        head = new Node;
        head->value = elem;
        head->next = 0;
        head->prev = 0;
        tail = head;
    } else {
        Node* temp = new Node;
        temp->value = elem;
        temp->next = 0;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void DoubleLinkedList::addAtIndex(int index, int elem) {
    if(index == 0){
        addFirst(elem);
    } else if(index == len){
        addLast(elem);
    } else {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            if(temp == 0){
                break;
            }
            temp = temp->next;
        }
        Node* newNode = new Node;
        newNode->value = elem;
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

void DoubleLinkedList::delFirst() {
    if(head != 0){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

}

void DoubleLinkedList::delLast() {
    if(head != 0){
        if(head == tail){
            delete head;
            head = 0;
            tail = 0;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        temp->prev->next = 0;
        delete temp;
    }

}

void DoubleLinkedList::delIndex(int index) {
        if(head == 0){
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            if(temp == 0){
                break;
            }
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;

}

void DoubleLinkedList::delValue(int value) {
    int index = find(value);
    if(index != -1){
        delIndex(index);
    }
}

int DoubleLinkedList::find(int val) {
    int index = 0;
    Node* temp = head;
    while(temp != 0){
        if(temp->value == val){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}



DoubleLinkedList::DoubleLinkedList() {
    head = 0;
    tail = 0;
    len = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
    while(head != 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void DoubleLinkedList::print() {
    Node* temp = head;
    std::cout << '[';
    while(temp != 0){
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << ']' <<std::endl;
}
