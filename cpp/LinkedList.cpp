//
// Created by Marcin on 07.03.2023.
//

#include "../headers/LinkedList.h"
#include <iostream>
LinkedList::LinkedList() {
    this->head = nullptr;
}

int LinkedList::get(int index){
    ListNode* current = head;
    if(current == nullptr) return -2147483648;
    while(index > 0 && current->next != nullptr){
        current = current->next;
        index--;
    }
    if(index == 0) return current->val;
    return -2147483648;

}
bool LinkedList::add(int element){
    auto* current = head;
    if(current == nullptr){
        head = new ListNode();
        head->val = element;
        return true;
    }
    while(current->next != nullptr) current = current->next;
    auto* newNode = new ListNode();
    current->next = newNode;
    newNode->previous = current;
    newNode->val = element;
    return true;
}
bool LinkedList::addFirst(int element){
    auto* l = new ListNode();
    l->val = element;
    l->next = head;
    head->previous = l;
    head = l;
    return true;
}
bool LinkedList::addAt(int,int){return true;}
bool LinkedList::remove(int index){
    auto* current = head;
    while(current->next != nullptr && index>0)
        current = current->next;
    if(index>0) return false;
    current->previous->next = current->next;
    current->next->previous = current->previous;
    delete current;
    return true;
}
bool LinkedList::removeFirst(){
    if(head == nullptr) return false;
    head->next->previous = nullptr;
    auto* tmp = head;
    delete head;
    head = tmp;
    return true;
}
bool LinkedList::removeLast(){
    if(head == nullptr) return false;
    auto* current = head;
    while(current->next != nullptr) current = current->next;
    current->previous->next = nullptr;
    delete current;
    return true;
}
int LinkedList::find(int){return 0;}
void LinkedList::print(){
    auto* current = head;
    std::cout << "[";
    while(current->next != nullptr){
        std::cout<< current->val << ",";
        current = current->next;
    }
    std::cout << current->val << "]\n";

}
LinkedList::~LinkedList(){

}


