//
// Created by Marcin on 07.03.2023.
//

#ifndef P1_LISTNODE_H
#define P1_LISTNODE_H


class ListNode {
public:
    ListNode(ListNode *pNode);

    ListNode* next;
    ListNode* previous;
    int val;
    ListNode();
    ~ListNode();
};


#endif //P1_LISTNODE_H
