//
// Created by Marcin on 10.04.2023.
//

#ifndef SDIZO1_UI_H
#define SDIZO1_UI_H


class UI {
private:
    enum structs {ARRAY, LIST, HEAP,RBTREE};
    enum actions {INIT,ADD_FIRST,ADD_LAST,ADD_AT,DEL_FIRST,DEL_LAST,DEL_AT,FIND,PRINT};

    int structure;
    int action;
    void* structurePointer;
    bool chooseStructure();
    bool chooseAction();
    bool chooseArrayAction();
    bool chooseListAction();
    bool chooseHeapAction();
    bool chooseRBTreeAction();
    void structureChoiceMade();
    void actionChoiceMade();

    void arrayAction();
    void listAction();
    void heapAction();
    void rbTreeAction();

public:
    void ui();
};


#endif //SDIZO1_UI_H
