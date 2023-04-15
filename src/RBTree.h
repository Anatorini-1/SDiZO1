//
// Created by Marcin on 09.04.2023.
//

#ifndef SDIZO1_RBTREE_H
#define SDIZO1_RBTREE_H


class RBTree {
private:
    enum {BLACK,RED};
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node* parent;
        bool color; // 0 - black, 1 - red
    };
    Node* root;
    Node* nil;
    int len;
    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void recolor(Node* x);
    Node* getUncle(Node* x);
    Node* getGrandparent(Node* x);
    Node* getSibling(Node* x);
    void repairInsert(Node* n);
    void repairDelete(Node* x);
    Node* predecessor(Node* n);
    Node* successor(Node* n);
    Node* findMin(Node* n);
    Node* findMax(Node* n);
    void del(Node* n);

public:
    void add(int elem);
    void del(int val);
    Node* find(int val);
    RBTree();
    ~RBTree();
    void print();
    void printTree(Node* node);


};


#endif //SDIZO1_RBTREE_H
