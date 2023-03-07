//
// Created by Marcin on 07.03.2023.
//

#include "../headers/LinkedList.h"
#include <iostream>
LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

int LinkedList::get(int index){
    auto* n = head;
    if(head == nullptr){
        return INT_MIN;
    }
    while(index && n->next != nullptr){
        index--;
        n = n -> next;
    }
    if(index == 0) return n->val;
    return INT_MIN;
}
bool LinkedList::add(int element){
    if(head == nullptr){
        head = new ListNode();
        head->val = element;
        tail = head;
        return true;
    }
    tail->next = new ListNode(element,tail,nullptr);
    tail = tail->next;
    return true;
}
bool LinkedList::addFirst(int element){
    if(head == nullptr){
        head = new ListNode(element,nullptr,nullptr);
        tail = head;
        return true;
    }
    auto* n = new ListNode(element, nullptr,head);
    head->previous = n;
    head = n;
    return true;
}
bool LinkedList::addAt(int index,int value){
    if(head == nullptr){
        head = new ListNode();
        tail = head;
    }
    auto* n = head;
    while(index){
        if(n -> next != nullptr) n = n->next;
        else {
            n -> next = new ListNode(0,n,nullptr);
            n = n -> next;
        }
        index--;
    }
    n -> previous->next = new ListNode(value,n ->previous,n);
    n -> previous = n->previous->next;
    return true;
}
bool LinkedList::remove(int index){
    if(index == 0) removeFirst();
    auto* current = head;
    if(current == nullptr) return false;
    while(index){
        index--;
        if(current->next == nullptr) break;
        current = current->next;
    }
    if(index == 0) {
        current->previous->next = current->next;
        if(current->next != nullptr)
            current->next -> previous = current->previous;
        delete current;
        return true;
    }
    return false;
}
bool LinkedList::removeFirst(){
    if(head == nullptr) return false;
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        return true;
    }
    head->next->previous = nullptr;
    auto* tmp = head ->next;
    delete head;
    head = tmp;
    return true;
}
bool LinkedList::removeLast(){
    if(head == nullptr) return false;
    tail = tail ->previous;
    delete tail -> next;
    tail -> next = nullptr;
    return true;
}
int LinkedList::find(int element){
    int index = 0;
    auto* n = head;
    while(n -> next != nullptr && n->val != element){
        n = n -> next;
        index++;
    }
    if(n->val == element) return index;
}
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
    if(head == nullptr) return;
    auto* tmp = head;
    while(tmp->next != nullptr){
        tmp = tmp->next;
        delete tmp->previous;
    }
    delete tmp;
}
bool LinkedList::addLast(int element) {
    if(head == nullptr){
        head = new ListNode(element,nullptr,nullptr);
        tail = head;
        return true;
    }
    tail->next = new ListNode(element,tail,nullptr);
    tail = tail->next;
}


