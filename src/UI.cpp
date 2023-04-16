//
// Created by Marcin on 10.04.2023.
//

#include "UI.h"
#include <iostream>
#include <windows.h>
#include "Array.h"
#include "DoubleLinkedList.h"
#include "Heap.h"
#include "RBTree.h"
using namespace std;
void UI::ui() {
    cout << "------ Welcome ------" << endl;
    while(chooseStructure()){
        structureChoiceMade();
        while (chooseAction()) {
            system("cls");
            actionChoiceMade();
        }
    }



}

bool UI::chooseStructure() {

    cout << endl;
    cout << "Choose a structure: " << endl;
    cout << "0. Array" << endl;
    cout << "1. Double Linked List" << endl;
    cout << "2. Heap" << endl;
    cout << "3. Red-Black Tree" << endl;
    cout << "*. Exit" << endl;
    cin >> structure;
    cout << endl;
    if(structure < 0 || structure > 3) {
        return false;
    }

    return true;


}

bool UI::chooseAction() {
    switch(structure){
        case ARRAY:
            return chooseArrayAction();
        case LIST:
            return chooseListAction();
        case HEAP:
            return chooseHeapAction();
        case RBTREE:
            return chooseRBTreeAction();
        default:
            return false;
    }
}

bool UI::chooseArrayAction() {
    cout << "----------------------" << endl;
    cout << "Choose an action (Array): " << endl;
    cout << "0. Initialize" << endl;
    cout << "1. Add First" << endl;
    cout << "2. Add Last" << endl;
    cout << "3. Add at Index" << endl;
    cout << "4. Delete First" << endl;
    cout << "5. Delete Last" << endl;
    cout << "6. Delete at Index" << endl;
    cout << "7. Find" << endl;
    cout << "8. Print" << endl;
    cout << "9. Load from file" << endl;
    cout << "10. Exit/Change Structure" << endl;
    cin >> action;
    if(action < 0 || action >= 10) {
        delete (Array*)structurePointer;
        return false;
    }
    return true;

}

bool UI::chooseListAction() {
    cout << "----------------------" << endl;
    cout << "Choose an action (LinkedList): " << endl;
    cout << "0. Initialize" << endl;
    cout << "1. Add First" << endl;
    cout << "2. Add Last" << endl;
    cout << "3. Add at Index" << endl;
    cout << "4. Delete First" << endl;
    cout << "5. Delete Last" << endl;
    cout << "6. Delete at Index" << endl;
    cout << "7. Find" << endl;
    cout << "8. Print" << endl;
    cout << "9. Load from file" << endl;
    cout << "10. Exit/Change Structure" << endl;
    cin >> action;
    if(action < 0 || action >= 10) {
        delete ((DoubleLinkedList*)structurePointer);
        return false;
    }
    return true;
}

bool UI::chooseHeapAction() {
    cout << "----------------------" << endl;
    cout << "Choose an action (Heap): " << endl;
    cout << "0. Initialize" << endl;
    cout << "1. Add" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Find" << endl;
    cout << "4. Print" << endl;
    cout << "5. Load from file" << endl;
    cout << "6. Exit/Change Structure" << endl;

    cin >> action;
    if(action < 0 || action >= 6) {
        delete ((Heap*)structurePointer);
        return false;
    }
    switch(action){
        case 0:
            action = INIT;
            break;
        case 1:
            action = ADD_FIRST;
            break;
        case 2:
            action = DEL_FIRST;
            break;
        case 3:
            action = FIND;
            break;
        case 4:
            action = PRINT;
            break;
        case 5:
            action = LOAD;
            break;
        default:
            return false;
    }
    return true;
}

bool UI::chooseRBTreeAction() {
    cout << "----------------------" << endl;
    cout << "Choose an action (RBTree): " << endl;
    cout << "0. Initialize" << endl;
    cout << "1. Add" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Find" << endl;
    cout << "4. Print" << endl;
    cout << "5. Load from file" << endl;
    cout << "6. Exit/Change Structure" << endl;

    cin >> action;
    if(action < 0 || action >= 6) {
        delete ((RBTree*)structurePointer);
        return false;
    }
    switch(action){
        case 0:
            action = INIT;
            break;
        case 1:
            action = ADD_FIRST;
            break;
        case 2:
            action = DEL_FIRST;
            break;
        case 3:
            action = FIND;
            break;
        case 4:
            action = PRINT;
            break;
        case 5:
            action = LOAD;
            break;
        default:
            return false;
    }
    return true;
}

void UI::structureChoiceMade() {
    switch (structure) {
        case ARRAY:
            structurePointer = new Array();
            break;
        case LIST:
            structurePointer = new DoubleLinkedList();
            break;
        case HEAP:
            structurePointer = new Heap();
            break;
        case RBTREE:
            structurePointer = new RBTree();
            break;
    }
}

void UI::actionChoiceMade() {
    switch(structure){
        case ARRAY:
            arrayAction();
            break;
        case LIST:
            listAction();
            break;
        case HEAP:
            heapAction();
            break;
        case RBTREE:
            rbTreeAction();
            break;
    }
}

void UI::arrayAction() {
    switch(action){
        case INIT:
            delete (Array*)structurePointer;
            structurePointer = new Array();
            break;
        case ADD_FIRST:
            int value;
            cout << "Enter value: ";
            cin >> value;
            ((Array*)structurePointer)->addFirst(value);
            break;
        case ADD_LAST:
            cout << "Enter value: ";
            cin >> value;
            ((Array*)structurePointer)->addLast(value);
            break;
        case ADD_AT:
            int index;
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            ((Array*)structurePointer)->addAtIndex(index,value);
            break;
        case DEL_FIRST:
            ((Array*)structurePointer)->delFirst();
            break;
        case DEL_LAST:
            ((Array*)structurePointer)->delLast();
            break;
        case DEL_AT:
            cout << "Enter index: ";
            cin >> index;
            ((Array*)structurePointer)->delIndex(index);
            break;
        case FIND:
            cout << "Enter value: ";
            cin >> value;
            cout << "Index: " << ((Array*)structurePointer)->find(value) << endl;
            break;
        case PRINT:
            ((Array*)structurePointer)->print();
            break;
        case LOAD:
            string fileName;
            cout << "Enter file name: ";
            cin >> fileName;
            ((Array*)structurePointer)->loadFromFile(fileName);
            break;
    }
}

void UI::listAction() {
    switch(action){
        case INIT:
            delete (Array*)structurePointer;
            structurePointer = new DoubleLinkedList();
            break;
        case ADD_FIRST:
            int value;
            cout << "Enter value: ";
            cin >> value;
            ((DoubleLinkedList*)structurePointer)->addFirst(value);
            break;
        case ADD_LAST:
            cout << "Enter value: ";
            cin >> value;
            ((DoubleLinkedList*)structurePointer)->addLast(value);
            break;
        case ADD_AT:
            int index;
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            ((DoubleLinkedList*)structurePointer)->addAtIndex(index,value);
            break;
        case DEL_FIRST:
            ((DoubleLinkedList*)structurePointer)->delFirst();
            break;
        case DEL_LAST:
            ((DoubleLinkedList*)structurePointer)->delLast();
            break;
        case DEL_AT:
            cout << "Enter index: ";
            cin >> index;
            ((DoubleLinkedList*)structurePointer)->delIndex(index);
            break;
        case FIND:
            cout << "Enter value: ";
            cin >> value;
            cout << "Index: " << ((DoubleLinkedList*)structurePointer)->find(value) << endl;
            break;
        case PRINT:
            ((DoubleLinkedList*)structurePointer)->print();
            break;
        case LOAD:
            string fileName;
            cout << "Enter file name: ";
            cin >> fileName;
            ((DoubleLinkedList*)structurePointer)->loadFromFile(fileName);
            break;
    }
}

void UI::heapAction() {
    int value;
    switch (action) {
        case INIT:
            delete (Heap *) structurePointer;
            structurePointer = new Heap();
            break;
        case ADD_FIRST:
            cout << "Enter value: ";
            cin >> value;
            ((Heap *) structurePointer)->add(value);
            break;
        case DEL_FIRST:
            cout << "Enter value: ";
            cin >> value;
            ((Heap *) structurePointer)->del(value);
            break;
        case FIND:
            cout << "Enter value: ";
            cin >> value;
            cout << "Index: " << ((Heap *) structurePointer)->find(value) << endl;
            break;
        case PRINT:
            ((Heap *) structurePointer)->print();
            break;
            case LOAD:
            string fileName;
            cout << "Enter file name: ";
            cin >> fileName;
            ((Heap *) structurePointer)->loadFromFile(fileName);
            break;
    }
}

void UI::rbTreeAction() {
    int value;
    switch (action) {
        case INIT:
            delete (RBTree *) structurePointer;
            structurePointer = new RBTree();
            break;
        case ADD_FIRST:
            cout << "Enter value: ";
            cin >> value;
            ((RBTree *) structurePointer)->add(value);
            break;
        case DEL_FIRST:
            cout << "Enter value: ";
            cin >> value;
            ((RBTree *) structurePointer)->del(value);
            break;
        case FIND:
            cout << "Enter value: ";
            cin >> value;
            cout << "Index: " << ((RBTree *) structurePointer)->find(value) << endl;
            break;
        case PRINT:
            ((RBTree *) structurePointer)->print();
            break;
        case LOAD:
            string fileName;
            cout << "Enter file name: ";
            cin >> fileName;
            ((RBTree *) structurePointer)->loadFromFile(fileName);
            break;


    }
}
